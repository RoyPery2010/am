#include "./am.c"
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./ebasm <input.ebasm> <output.am>\n");
        fprintf(stderr, "ERROR: expected input and output\n");
        exit(1);
    }
    const char *input_file_path = argv[1];
    const char *output_file_path = argv[2];
    String_View source = slurp_file(input_file_path);
    am.program_size = am_translate_source(source, am.program, AM_PROGRAM_CAPACITY);
    am_save_program_to_file(am.program, am.program_size, output_file_path);
    return 0;
}