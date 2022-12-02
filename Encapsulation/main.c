#include "p_variable.h"
#include <stdio.h>

int main()
{
    struct Con * Meghna;
    Meghna = create_contact();
    printf( "Mobile number: %d\n", Meghna->mob_number ); // This should cause compile time error as we are //trying to access the private struct member
    print_contact(Meghna);
    delete_contact( Meghna  );
    return 0;

}
