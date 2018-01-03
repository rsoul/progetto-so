



int main(int argc, char *argv[]) {
  
  int sd, rc, i;
  struct sockaddr_in cliAddr, remoteServAddr;
  struct hostent *h;
FILE* filein;
long lSize;
char *buffer;

  /* Prendiamo i commandi da arg */
  if(argc<3) {
    printf("usage : %s <server> <data1> ... <dataN> \n", argv[0]);
    exit(1);
  }

  /* Prendiamo l'indirizzo ip del server */
  h = gethostbyname(argv[1]);
  if(h==NULL) {
    printf("%s: host sconosciuto '%s' \n", argv[0], argv[1]);
    exit(1);
  }

  printf("%s: invio dati a '%s' (IP : %s) \n", argv[0], h->h_name,
	 inet_ntoa(*(struct in_addr *)h->h_addr_list[0]));

  remoteServAddr.sin_family = h->h_addrtype;
  memcpy((char *) &remoteServAddr.sin_addr.s_addr, 
	 h->h_addr_list[0], h->h_length);
  remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);

  /* Creazione socket */
  sd = socket(AF_INET,SOCK_DGRAM,0);
  if(sd<0) {
    printf("%s: impossibile aprire socket \n",argv[0]);
    exit(1);
  }
  
  /* bind any port */
  cliAddr.sin_family = AF_INET;
  cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  cliAddr.sin_port = htons(0);
  
  rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
  if(rc<0) {
    printf("%s: cannot bind port\n", argv[0]);
    exit(1);
  }



  //open file
filein = fopen("image.jpg","rb+");
//get its size
fseek(filein, 0, SEEK_END);
lSize = ftell(filein);
rewind (filein);

//malloc the buffer big enough for image data

buffer = (char*) malloc (lSize);
//Lettura img nel buffer 
fread (buffer,1,lSize,filein);


//...create duplicate image (works ok)


  // Invio dati

  for(i=2;i<argc;i++) {
    rc = sendto(sd, buffer, sizeof(buffer)+1, 0, 
		(struct sockaddr *) &remoteServAddr, 
		sizeof(remoteServAddr));

    if(rc<0) {
      printf("%s: impossibile inviare i dati %d \n",argv[0],i-1);
      close(sd);
      exit(1);
    }

  }
  
  return 1;

}
