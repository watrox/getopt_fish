#include <iostream>
#include <getopt.h>
#include <cstring>
#include <cstdio>

#define STAT_PARSE_OK 0

struct p_opt {
	int i;
	char *file;
	
	double value;
	bool flag;
};

void init_popt (struct p_opt *p){
	p->file=NULL;
	p->flag=0;
}

int parse_args(int argc, char * argv[], struct p_opt *p){

	int rez = 0;
	int optid = 0;

	const char* short_options = "i:f:v:b";

	const struct option long_options[] = {
		{"flag", no_argument,       0,    'b'},
		{"int",  required_argument, NULL,    'i'},
		{"val",  required_argument, NULL,    'v'},
		{"file", required_argument, NULL,    'f'},
		{NULL,0,NULL,0}
	};

	while ((rez=getopt_long(argc, argv, short_options, long_options, &optid))!=-1){
		
		std::cout << "rez=" << rez << std::endl;
		switch (rez){
			case 'v':{
				p->value=atof(optarg);
				break;
			};
			case 'b':{
				p->flag=true;
				break;
			};
			case 'i':{
				//std::cout << "ot=" << optarg << std::endl;				
				//printf ("qwe %s", optarg);
				if (optarg != NULL){
					p->i=atoi(optarg);
				} else {
					std::cout << "wrong format for int\n" << std::endl;
				}
				break;
			};
			case 'f':{
				p->file = new char [strlen(optarg)];
				strcpy (p->file, optarg);
				
				std::cout << "ot=" << optarg << std::endl;
				break;
			};
		};
		
	};

	return STAT_PARSE_OK;
}

int main(int argc, char *argv[]){

	struct p_opt ppars;

	init_popt (&ppars);
//	ppars.file= new char [256];

	int parse_stat = parse_args(argc, argv, &ppars);

	std::cout << "i = " << ppars.i << std::endl \
		  << "file = " << ppars.file << std::endl \
		  << "flag = " << ppars.flag << std::endl \
		  << "value = " << ppars.value << std::endl ;

	std::cout << "work" << std::endl;

//	delete [] ppars.file;

	return 0;
}
