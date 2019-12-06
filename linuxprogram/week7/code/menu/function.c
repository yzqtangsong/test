#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void newfile()
{
	FILE *fp;
	char filename[10];
	printf("please input file name :");
	scanf("%s",&filename);
	fp=fopen(&filename,"w+");
	if(fp==NULL)
	{
		perror("open file :fail or file exit");
	}else{
		printf("new file sucessed\n");
	}
	fclose(fp);
}

void readfile()
{
	FILE *fp;
	char buffer[20];
	char filename[10];
	printf("please inout file a=name :");
	scanf("%s",&filename);
	fp=fopen(&filename,"r");
	if(fp==NULL)
	{
		perror("read file failed or file is not exist\n");
	}else{
		while(fgetc(fp)!=EOF)
		{
			fseek(fp,0,SEEK_SET);
			fgets(buffer,20,fp);
			printf("%s",buffer);
	
		}
	}
	fclose(fp);
	
}
void writefile()
{
	FILE *fp;
	char fname[10];
	char content[200];
	printf("please input file name:");
	scanf("%s",&fname);
	fp=fopen(&fname,"wt+");
	printf("please input the content:\n");
	getchar();
	fgets(content,199,stdin);
	fputs(content,fp);
	if(fp==NULL)
	{
		perror("write file failed\n");
	}else{
		printf("write file successde\n");	
	}
	fclose(fp);
}
void modify()
{
	FILE *fp;
	char fname[10];
	int choice;
	printf("please intput file name:");
	scanf("%s",&fname);
	printf("-----------------------\n");
	printf("0.break\n");
	printf("1.write only\n");
	printf("2.read only\n");
	printf("3.wirte and read \n");
	printf("please input your choice[0-6]:\n");	
	scanf("%d",&choice);
	switch(choice)
	{
	case 0:
		break;
	case 1:
		chmod(&fname,S_IWUSR);
		break;
	case 2:
		chmod(&fname,S_IRUSR);
		break;
	case 3:
		chmod(&fname,S_IWUSR|S_IRUSR);
		break;
	default:
		printf("please input 0-3\n");
	}
}

void menu(){
	printf("************************************\n");
	printf("	0.exit;\n");
	printf("	1.new file;\n");
	printf("	2.write file;\n");
	printf("	3.read file;\n");
	printf("	4.modify permission;\n");
	printf("	5.look or modify permission;\n");
	printf("************************************\n");
	printf("Please input your choice(0-5):");
	choose();
}

void choose()
{
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
	case 0:
		exit(0);
	case 1:
		newfile();
		break;
	case 2:
		writefile();
		break;
	case 3:
		readfile();
		break;
	case 4:
	  	modify();
		break;
	default:
		printf("please input 0-5\n");
	}
}
