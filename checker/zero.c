# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void remove_zero(char **s, char **ref)
{
    int     zeros;
    int     i;
    int     len;
    char    *new_s;
    char    *new_ref;
    if (!*s || !*ref || ((len = strlen(*s)) != (int)strlen(*ref)))
        return ;
    i = -1;
    zeros = 0;
    while ((*ref)[++i] != '\0')
    {
        if ((*ref)[i] == '0')
            zeros++;
    }
    //printf("%d\n", zeros);
    if (!zeros)
        return ;
    len -= zeros;
    i = -1;
    if (!(new_s = ((char*)malloc((len + 1) * sizeof(char)))))
            return ;
    if (!(new_ref = ((char*)malloc((len + 1) * sizeof(char)))))
            return ;
    while ((*s)[++i] != '\0')
    {
        if ((*ref)[i] != '0')
        {
            new_ref[i] = (*ref)[i];
            new_s[i] = (*s)[i];
            printf("%c\n", new_ref[i]);
        }
    }
    printf("%d\n", i);
    new_ref[i] = '\0';
    new_s[i] = '\0';
    //printf("%s\n", new_ref);
    free(*s);
    free(*ref);
    (*s) = strdup(new_s);
    (*ref) = strdup(new_ref);
    //printf("%s\n", *s);
}
int main()
{
    char *s;
    char *ref;

    s = strdup("hellozallo");
    ref = strdup("hello0allo");
    remove_zero(&s, &ref);
    printf("%s\n", s);
    printf("%s\n", ref);
    return (0);
}