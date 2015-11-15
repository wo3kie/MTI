## Copyright (C) 2005 Łukasz Czerwiński

## MTI, Master Thesis Interpreter
OK. It was not my [master thesis](https://github.com/wo3kie/mtc). I wish just have both names similar (mtc, mti).

## Website
GitHub source code  : https://github.com/wo3kie/MTI

## Requirements
* C++03
* flex++ >= 2.5.35, optional, only if you change interpreter.l
* bison++ >= 1.21.9-1, optional, only if you change interpreted.y
  
## How to build it?
make

## How to run it?
./mti example.mti

## How to write a program?
Please follow examples in 'example.mti' file. Shortly speaking mti supports C syntax with no structs. However arguments are passed to functions like by reference.

```
double pow2( double d ){
    return d * d;
}

// arguments are passed by reference
double setZero( double d ){
    d = 0;
}

// recursion
double factorial( double d ){
    if( d == 0 ){
        return 1;
    }
    else{
        return d * factorial( d - 1 );
    }
}

// return does not finish function's execution.
// it sets value to be returned by function.
double return3(){
    return 1;
    return 2;
    return 3;
}

double main()
{
    // simple arithmetic
    if( ( 1 + 2 * 3 ) == 7 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // sin, cos, log...
    if( ( sin( 20 ) * sin( 20 ) + cos( 20 ) * cos( 20 ) ) == 1 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // functions
    if( pow2( 5 ) == 25 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );
    
    // variable are set to 0
    double d;
    if( d == 0 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // arguments are passed by reference
    d = 1;
    setZero( d );
    if( d == 1 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // recursion
    if( factorial( 4 ) == 24 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // return does not finish function's execution.
    if( return3() == 3 ){
        printf( "OK" );
    }
    else{
        printf( ":(" );
    }
    printf( endl );

    // I/O
    printf( "Enter a number (not 13)..." );
    scanf( d );
    if( d == 13 ){
        printf( ":(" );
    }
    else{
        printf( "OK" );
    }
    printf( endl );
    
    printf( "." );
    printf( endl );

    return 0;
}
```

