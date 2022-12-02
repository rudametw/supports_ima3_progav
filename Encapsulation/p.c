#include "p_variable.h" //we hav included header file in this file so as to access the structure members. This is //an indirect way of accessing structures and thus implementing encapsulation.
#include <stdio.h>
#include <stdlib.h>
struct Con //structure definition containing two members. Both the members are integer type
{
    int mob_number;
    int flat_number;

};
struct Con * create_contact() // structure declaration. In this code section we allocate memory for the data we //need to input in the above defined members. Malloc function allocates the memory.
{
    struct Con * some_contact;
    some_contact = malloc(sizeof(struct Con));
    some_contact->mob_number = 1234567891;
    some_contact->flat_number = 541;
    return( some_contact  );

}
void delete_contact( struct Con * some_contact  )
{
    free(some_contact); // this is tandard C function to de- allocate the memory. It frees up the memory so that //the same can be used by other programs.

}
void print_contact( struct Con * some_contact  )
{
    printf( "Mobile number: %d\n", some_contact->mob_number  );
}
