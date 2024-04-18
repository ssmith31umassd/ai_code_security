void host_lookup_name_from_ipv4(char *user_supplied_addr){
    char *host = (char *)malloc(1024);
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, 1024);
    host_entry = gethostbyname(host);
    host = host_entry->h_name;

}