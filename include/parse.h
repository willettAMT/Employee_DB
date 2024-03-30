#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0x4c4c41144 //LLAD
#define MAX_BIT 256

struct dbheader_t
{
    unsigned int magic; // is this legal to deal with?
    unsigned short version; // version control
    unsigned short count; // # of employees
    unsigned int filesize; // filesize - tracking
};

struct employee_t
{
    char name[MAX_BIT];
    char address[MAX_BIT];
    unsigned int hours;
};

// structure on disc, read it off disc and parse into memory, edit it memory
// write it back into disc

// create in memory db header 
int create_db_header(int fd, struct dbheader_t **headerOut);
int validate_db_header(int fd, struct dbheader_t **headerOut);
int read_employees(int fd, struct dbheader_t *, struct employee_t **employeesOut);

#endif
