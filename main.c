#include "monty.h"
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

bus_t bus = {NULL, NULL, NULL, 0};

ssize_t my_getline(char **content, size_t *size, FILE *file) {
    char *buffer;
    size_t capacity = 50;
    size_t length = 0;
    int character;
    
    buffer = malloc(capacity * sizeof(char));
    if (!buffer) return -1;

    while ((character = fgetc(file)) != EOF && character != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            buffer = realloc(buffer, capacity * sizeof(char));
            if (!buffer) return -1;
        }
        buffer[length++] = character;
    }

    if (length == 0 && character == EOF) {
        free(buffer);
        return -1;
    }

    buffer[length++] = '\0';
    *content = buffer;
    *size = length;

    return length - 1;
}



/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *content = NULL;
	size_t size = 0;
	ssize_t read_line = 1;
	unsigned int counter = 0;

	/* Check if the number of arguments is correct */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the file */
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read and execute each line in the file */
	while ((read_line = my_getline(&content, &size, file)) > 0)
	{
		bus.content = content;
		counter++;
		execute(content, &stack, counter, file);
		free(content);
		content = NULL;
	}

	/* Clean up */
	free_stack(stack);
	fclose(file);

	return (0);
}

