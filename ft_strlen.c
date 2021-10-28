int ft_strlen(const char *s)
{
//    int count = 0;
//    while(*s!='\0')
//    {
//        count++;
//        s++;
//    }
//    return count;
    int i;
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return(i);

}