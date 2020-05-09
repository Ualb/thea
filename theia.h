
struct row {

};

struct sheet {
    const char *name;
    unsigned int *is_created;
    unsigned int *seek_point;
};


struct response {
    unsigned int *is_ok;
    unsigned int *id_line;
    unsigned int *error;
};

struct row *add(char *line) {}

struct response *create(char *sheet) {} 

struct response *edit(char *sheet, char *condition) {}

struct response *edit(char *sheet) {}

struct response *remove(char *sheet, char *condition) {}

struct response *del(char *sheet) {}