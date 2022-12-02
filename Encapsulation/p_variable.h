#ifndef PRIVATE_VARIABLE
#define PRIVATE_VARIABLE
//struct Con; // It is a variable to store contact
struct Con * create_contact(); // functional call to create function
void delete_contact( struct Con * some_contact  ); // functional call to delete function
void print_contact( struct Con * some_contact  );
#endif //PRIVATE_VAR
