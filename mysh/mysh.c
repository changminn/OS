//myshell by 32153682 이창민, ckdals0115@naver.com
//mysh.c 
#include"mysh.h"
void main(){
	write(STDOUT_FILENO,"+------------------------------------------------------------------------------------+\n",88);
	write(STDOUT_FILENO,"|MYSHELL                                                                             |\n",88);
	write(STDOUT_FILENO,"|------------------------------------------------------------------------------------|\n",88);
	write(STDOUT_FILENO,"|QUIT : quit                                                                         |\n",88);
	write(STDOUT_FILENO,"+------------------------------------------------------------------------------------+\n",88);

	while(1){
		//write시 쓰레기값 없게 초기화
		char CommandLine[MAX]={0};
		char PWD[MAX]={0};
		char** command;
		int read_size;
		int errno;
		/*char *getcwd(char *buf, int maxlen); => get pwd "unistd.h*/
		getcwd(PWD,MAX);
 	/////////////////////////////////////////////////////////////////
	//화면에 출력, write가 printf보다 빠르므로 write를 써봣음..
		write(STDOUT_FILENO, "sys153682@myshell:~", 20);
		write(STDOUT_FILENO, PWD, MAX);
		write(STDOUT_FILENO, "$ ",3);
	/////////////////////////////////////////////////////////////////
	//읽기
		/*입력받은 커맨드 command로 읽음*/
		read_size = read(STDIN_FILENO, CommandLine, MAX);
		//input enter
		if(read_size == 1){
			continue;}
	////////////////////////////////////////////////////////////////
	//명령어 구분하고 실행
		command = get_tokens(CommandLine);
		if(!strcmp(command[0],"quit")){
			printf("+------------------------------------------------------------------------------------+\n");
			printf("|BASH                                                                                |\n");
			printf("+------------------------------------------------------------------------------------+\n");
			exit(1);}
		else{
			execute_com(command);
		}
		
	}
}

