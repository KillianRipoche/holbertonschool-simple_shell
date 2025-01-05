#include "main.h"
/** */
char *getenv(const char *name, char **env)
{
	int i;
	char **environ;
	char *env = environ[i];
	char *eq_pos = strchr(env[i], '=');
	size_t name_len;

	if (name == NULL || env == NULL)
		return(NULL);

	name_len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (eq_pos != NULL)
		{
			if (strncmp(env, name, name_len) == 0 && name_len == strlen(name))
				return (eq_pos + 1);
		}
	}

	return (NULL);
}
