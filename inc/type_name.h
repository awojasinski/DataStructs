#ifndef TYPE_NAME_H
#define TYPE_NAME_H

/*macro for type printing*/
#define type_name(exp) \
        (_Generic((exp), \
                    char: "char", unsigned char: "unsigned char", \
                    short: "short", unsigned short: "unsigned short", \
                    int: "int", unsigned int: "unsigned int", \
                    long: "long", unsigned long: "unsigned long", \
                    long long: "long long", unsigned long long: "unsigned long long", \
                    float: "float", \
                    double: "double", \
                    long double: "long double", \
                    void*: "void*", \
                    default: "?"))

#endif