int decodeFile(char* fName)
{
    FILE *f = fopen(fName, "r");
    if (!f)
    {
        return 1;
    }
    char buffer[100];
    fgets(buffer, 100, f);
    for (int i = 0; i < 100; i++)
    {
        buffer[i] = buffer[i] - 1;
    }
    fclose(f);
    return 0;
}