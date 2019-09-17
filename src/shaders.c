#include "game.h"

#define INFO_LOG_SIZE 1024

static char *read_file(const char *path)
{
	FILE *file;
	long length;
	char *content = NULL;

	file = fopen(path, "rb");
	if (!file)
		goto error;

	fseek(file, 0, SEEK_END);
	length = ftell(file);
	rewind(file);
	if (ferror(file))
		goto error;

	content = calloc(1, length + 1);
	if (!content)
		goto error;

	fread(content, 1, length, file);
	if (ferror(file))
		goto error;

	fclose(file);
	return content;

error:
	if (file)
		fclose(file);
	free(content);
	perror(path);
	return NULL;
}

static GLuint create_shader(const char *path, GLenum type)
{
	char info_log[INFO_LOG_SIZE];
	GLint success;
	GLuint out;
	const char *source;

	out = glCreateShader(type);
	source = read_file(path);
	if (!source)
		goto error;
	glShaderSource(out, 1, &source, NULL);
	free((void *)source);

	glCompileShader(out);
	glGetShaderiv(out, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(out, INFO_LOG_SIZE, NULL, info_log);
		puts(info_log);
		goto error;
	}
	return out;
error:
	glDeleteShader(out);
	return 0;
}

GLuint load_shader(const char *v, const char *f)
{
	char info_log[INFO_LOG_SIZE];
	GLint success;
	GLuint vertex = 0, fragment = 0, program = 0;

	vertex = create_shader(v, GL_VERTEX_SHADER);
	if (!vertex)
		goto error;

	fragment = create_shader(f, GL_FRAGMENT_SHADER);
	if (!fragment)
		goto error;

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, INFO_LOG_SIZE, NULL, info_log);
		puts(info_log);
		goto error;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	return program;

error:
	if (vertex)
		glDeleteShader(vertex);
	if (fragment)
		glDeleteShader(fragment);
	if (program)
		glDeleteProgram(program);
	return 0;
}
