#include "myapp.h"
#include "mywidget.h"

int main(int argc, char *argv[])
{
    MyApp w(argc,argv);
    MyWidget e;
    e.show();

    return w.exec();
}
