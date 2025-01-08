#include "main.h"
/** */
char *_getenv(const char *name, char **env)
{
	int i;
	size_t name_len;

	if (name == NULL || env == NULL)
		return NULL;

	name_len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		char *eq_pos = strchr(env[i], '=');

		if (eq_pos != NULL)
		{
			size_t var_len_name = eq_pos - env[i];

			if (strncmp(env[i], name, name_len) == 0 && name_len == var_len_name)
				return (eq_pos + 1);
		}
	}

	return (NULL);
}

int main(void)
{
	char *env[] = {
		"USER=root",
		"HOME=/root",
		"PATH=/usr/bin:/bin",
		NULL};

	char *value = _getenv("HOME", env);

	if (value != NULL)
		printf("HOME = %s\n", value);
	else
		printf("Variable non trouvée.\n");

	return (0);
}
