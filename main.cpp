// Version 1.0

#include "interpreter.h"
#include "wyjatki.h"

int main( int argc, char** argv){
    try{
        Interpreter interpreter( argc, argv);
        return interpreter.run();
    }
    catch( const std::exception& __error){
        std::cerr<< __error.what()<< std::endl;
    }
    catch( ...){
        std::cerr<< "No 'stl::exception&' error"<< std::endl;
    }
}
