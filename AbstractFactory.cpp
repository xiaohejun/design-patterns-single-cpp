#include <iostream>

using namespace std;

class Button {
public:
    virtual void paint() = 0;

    virtual ~Button() {}
};

class CheckBox {
public:
    virtual void paint() = 0;

    virtual ~CheckBox() {}
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;

    virtual CheckBox* createCheckBox() = 0;

    virtual ~GUIFactory() {}
};

class MacOsButton : public Button {
public:
    void paint() override
    {
        cout << "这是一个Mac下的按钮" << endl;
    }
};

class MacOsCheckBox : public CheckBox {
public:
    void paint() override
    {
        cout << "这是一个Mac下的check box" << endl;
    }
};

class MacOsFactory : public GUIFactory {
public:
    Button* createButton() override
    {
        return new MacOsButton();
    }

    CheckBox* createCheckBox() override
    {
        return new MacOsCheckBox();
    }
};

class WindowsButton : public Button {
public:
    void paint() override
    {
        cout << "这是一个Window下的按钮" << endl;
    }
};

class WindowsCheckBox : public CheckBox {
public:
    void paint() override
    {
        cout << "这是一个Windows下的check box" << endl;
    }
};

class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override
    {
        return new WindowsButton();
    }

    CheckBox* createCheckBox() override
    {
        return new WindowsCheckBox();
    }
};

class Application {
private:
    Button* button_;
    CheckBox* check_box_;

public:
    Application(GUIFactory &factory)
    {
        button_ = factory.createButton();
        check_box_ = factory.createCheckBox();
    }

    void paint()
    {
        button_->paint();
        check_box_->paint();
    }

    // TODO: 析构
};

void ClientCode(string type)
{
    GUIFactory* gui_factory = nullptr;
    if (type == "mac") {
        gui_factory = new MacOsFactory();
    } else if (type == "windows") {
        gui_factory = new WindowsFactory();
    }

    Application app(*gui_factory);
    app.paint();

    // int a[2];
    // a[3] = 0;

    delete gui_factory;
}

int main()
{
    ClientCode("mac");
    ClientCode("windows");
    return 0;
}