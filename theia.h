struct document {
    unsigned int *numbers_of_sheet;
    unsigned int *first_sheet;
};

struct row {
    const char *structure;
    unsigned int *this_memory_location;
    unsigned int *next_row;
};

struct sheet {
    const char *name;
    const char *structure; 
    unsigned int *this_memory_location;
    unsigned int *id_selected;
    unsigned int *next_sheet;
    unsigned int *numbers_of_data;
    unsigned int *first_row;
};


struct response {
    unsigned int *is_ok;
    unsigned int *id_line;
    unsigned int *error;
};

struct response *add(char *line) {}

struct response *create(char *sheet) {} 

struct response *edit(char *sheet, char *condition) {}

struct response *edit(char *sheet) {}

struct response *remove(char *sheet, char *condition) {}

struct response *del(char *sheet) {}

struct row *read(char *sheet, char *condition);