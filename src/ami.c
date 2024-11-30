#include "./am.c"
int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: ./ami <input.am>\n");
        fprintf(stderr, "ERROR: expected input\n");
        exit(1);
    }
    am_load_program_from_file(&am, argv[1]);
    for (int i = 0; i < 69 && !am.halt; ++i) {
        Err err = am_execute_inst(&am);
        am_dump_stack(stderr, &am);
        if (err != ERR_OK) {
            fprintf(stderr, "ERROR: %s\n", err_as_cstr(err));
            exit(1);
        }
    }
    am_dump_stack(stdout, &am);
    return 0;
}