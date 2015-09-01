#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE   1000000
#define SIZE_F 1000000.0
#define SIZE2  2000000

// Thank you!
// http://stackoverflow.com/questions/459691/best-timing-method-in-c
int main(){
    ///////////////////////////////////////////////////////////////////////////
    //
    // Setup stuff
    //
    ///////////////////////////////////////////////////////////////////////////
    int i;
    // Mallocing memory and populating the array.
    double* together = ( double * ) ( malloc( SIZE2 * sizeof(double) ) );
    for( i = 0; i < SIZE; ++i ){
        int index = 2 * i;
        together[ index ] = 1.0;
        together[ index + 1 ] = 1.0;
    }

    double xtotal = 0.0;
    double ytotal = 0.0;
    double xcenter = 0.0;
    double ycenter = 0.0;

    ///////////////////////////////////////////////////////////////////////////
    //
    // Adding xi and yi simultaneously, from one array.
    //
    ///////////////////////////////////////////////////////////////////////////
    printf( "Adding xi and yi simultaneously, from one array.\n" );
    clock_t start = clock(), diff;
    for( i = 0; i < SIZE; ++i ){
        int index = 2 * i;
        xtotal += together[ index ];
        ytotal += together[ index + 1 ];
    }

    xcenter = xtotal / SIZE_F;
    ycenter = ytotal / SIZE_F;

    diff = clock() - start;
    printf( "Time taken: %f\n\n", (double) diff );

    xtotal = 0.0;
    ytotal = 0.0;

    ///////////////////////////////////////////////////////////////////////////
    //
    // Adding xi and yi in two loops, both stored in one array.
    //
    ///////////////////////////////////////////////////////////////////////////
    printf( "Adding xi and yi in two loops, both stored in one array.\n" );
    start = clock(), diff;
    // x's first
    for( i = 0; i < SIZE2; i+=2 ){
        xtotal += together[ i ];
    }

    // now y's
    for( i = 1; i < SIZE2; i+=2 ){
        ytotal += together[ i ];
    }

    xcenter = xtotal / SIZE_F;
    ycenter = ytotal / SIZE_F;

    diff = clock() - start;
    printf( "Time taken: %f\n\n", (double) diff );

    ///////////////////////////////////////////////////////////////////////////
    //
    // More setup stuff
    //
    ///////////////////////////////////////////////////////////////////////////

    // Mallocing and populating the arrays
    double* xs = ( double * ) ( malloc( SIZE * sizeof( double ) ) );
    double* ys = ( double * ) ( malloc( SIZE * sizeof( double ) ) );
    for( i = 0; i < SIZE; ++i ){
        xs[ i ] = 1.0;
        ys[ i ] = 1.0;
    }

    xtotal = 0.0;
    ytotal = 0.0;

    ///////////////////////////////////////////////////////////////////////////
    //
    // Adding xi and yi in two loops; xi and yi stored in 2 separate arrays.
    //
    ///////////////////////////////////////////////////////////////////////////
    printf( "Adding xi and yi in two loops; xi and yi stored in 2 separate arrays.\n" );
    start = clock(), diff;
    // x's first
    for( i = 0; i < SIZE; ++i ){
        xtotal += xs[ i ];
    }

    // now y's
    for( i = 0; i < SIZE; ++i ){
        ytotal += ys[ i ];
    }

    xcenter = xtotal / SIZE_F;
    ycenter = ytotal / SIZE_F;

    diff = clock() - start;
    printf( "Time taken: %f\n\n", (double) diff );

    // Done!
    return 1;
}