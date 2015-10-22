#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc , char *argv[])
{
    int pipefd[2], result;
    char buf[1024];
    int flag = 0;
    pid_t pid;

    printf("%d\n", getpid());

    result = pipe(pipefd); //创建一个管道
    if(result == -1)
    {
        perror("pipe error:");
        exit(EXIT_FAILURE);
    }
    pid = fork(); //创建一个子进程
    if(pid == -1)
    {
        perror("fork  error:");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0)
    {
        if((close(pipefd[1])) == -1) //close write only read
        {
            perror("close write  error:");
            exit(EXIT_FAILURE);
        }
        while(1)  //循环读取数据
        {
            read(pipefd[0], buf, 1024); //最多读取1024个字节
            printf("read from pipe :  %s\n", buf);
            if(strcmp(buf, "exit") == 0) // if 读取到的字符串是exit
            {
                //父进程会接受到一个终止进程的信号，父进程会回收子进程的资源等
                exit(EXIT_SUCCESS);
            }
        }
    }
    else
    {
        //close read only write
        if((close(pipefd[0])) == -1)
        {
            perror("close read error:");
            exit(EXIT_FAILURE);
        }
        while(1)//循环写入内容
        {
            waitpid(pid, NULL, WNOHANG); //等待子进程退出
            if(flag == 1)
                exit(0);
            scanf("%s", buf);
            write(pipefd[1], buf, strlen(buf) + 1); //具体写多少个字节
            if(strcmp(buf, "exit") == 0)
            {
                flag = 1;
                sleep(1);//让子进程完全退出。
            }
        }
    }
    return 1;
}



/*

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int pipe_default[2];

int main()
{
    pid_t pid;
    char buffer[32];

    memset(buffer, 0, 32);
    if(pipe(pipe_default) < 0)
    {
        printf("Failed to create pipe!\n");
        return 0;
    }

    if(0 == (pid = fork()))
    {
        close(pipe_default[1]);
        sleep(5);
        if(read(pipe_default[0], buffer, 32) > 0)
        {
            printf("Receive data from server, %s!\n", buffer);
        }
        close(pipe_default[0]);
    }
    else
    {
        close(pipe_default[0]);
        if(-1 != write(pipe_default[1], "hello", strlen("hello")))
        {
            printf("Send data to client, hello!\n");
        }
        close(pipe_default[1]);
        waitpid(pid, NULL, 0);
    }

    return 1;
}

*/


/*
#include
#include
#include
#include
#include

int main(){
    int pipe_fd[2];
    pid_t pid;
    char buf_r[100];
    char *p_wbuf;
    int r_num;

    memset(buf_r,0,sizeof(buf_r));

    //创建管道
    if(pipe(pipe_fd)<0){
        printf("pipe create error\n");
        return -1;
    }

    if((pid=fork())==0){//表示在子进程中
        printf("\n");
        //关闭管道写描述符，进行管道读操作
        close(pipe_fd[1]);
        sleep(2);
        //管道描述符中读取
        if((r_num=read(pipe_fd[0],buf_r,100))>0){
            printf("%d numbers read from the pipe is %s\n",r_num,buf_r);
        }
        close(pipe_fd[0]);
        exit(0);
    }
    else if(pid>0){//表示在父进程中，父进程写
    //关闭管道读描述符，进行管道写操作
        close(pipe_fd[0]);
        if(write(pipe_fd[1],"Hello",5)!=-1)
            printf("parent write1 success!\n");
        if(write(pipe_fd[1],"Pipe",5)!=1)
            printf("parent write2 success!\n");
        close(pipe_fd[1]);
        sleep(3);
        waitpid(pid,NULL,0);
        exit(0);
    }
}
*/


