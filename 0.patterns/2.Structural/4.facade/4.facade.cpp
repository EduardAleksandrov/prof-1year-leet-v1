/*
    Facade
    Фасад
*/
#include <iostream>
using namespace std;

// Text Editor
class TextEditor {
public:
    void CreateCode() {
        cout << "Написание кода" << endl;
    }
    
    void Save() {
        cout << "Сохранение кода" << endl;
    }
};

// Compiler
class Compiler {
public:
    void Compile() {
        cout << "Компиляция приложения" << endl;
    }
};

// CLR (Common Language Runtime)
class CLR {
public:
    void Execute() {
        cout << "Выполнение приложения" << endl;
    }
    
    void Finish() {
        cout << "Завершение работы приложения" << endl;
    }
};

// Visual Studio Facade
class VisualStudioFacade {
private:
    TextEditor textEditor;
    Compiler compiler;
    CLR clr;

public:
    VisualStudioFacade(TextEditor te, Compiler comp, CLR clr) 
        : textEditor(te), compiler(comp), clr(clr) {}

    void Start() {
        textEditor.CreateCode();
        textEditor.Save();
        compiler.Compile();
        clr.Execute();
    }

    void Stop() {
        clr.Finish();
    }
};

// Programmer
class Programmer {
public:
    void CreateApplication(VisualStudioFacade& facade) {
        facade.Start();
        facade.Stop();
    }
};

// Main Function
int main() {
    TextEditor textEditor;
    Compiler compiler;
    CLR clr;
    
    VisualStudioFacade ide(textEditor, compiler, clr);
    
    Programmer programmer;
    programmer.CreateApplication(ide);
    
    return 0;
}