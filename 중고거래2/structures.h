#ifndef STRUCTURES_H
#define STRUCTURES_H

#define SIZE 50

struct Product {
    int productID;
    char productname[SIZE];
    double price;
    char des[500];
    char seller[SIZE];
    int sellerID;
};

struct User {
    int userID;
    char username[SIZE];
    char email[SIZE];
    char pwd[SIZE];
};

struct Admin {
    int adminID[SIZE];
    char adminpwd[SIZE];
};

#endif // STRUCTURES_H
