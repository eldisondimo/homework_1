#include "ros/ros.h"
#include "homework_1/Choice.h"
#include <unistd.h>
#include <termios.h>

// Get a char from the input keyboard without waiting the enter pressed button
char getch() {
        
char buf = 0;
struct termios old = {0};
        
    if (tcgetattr(0, &old) < 0)
      perror("tcsetattr()");
    
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    
    if (tcsetattr(0, TCSANOW, &old) < 0)
      perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
      perror ("read()");
    
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
      perror ("tcsetattr ~ICANON");
        
    return (buf);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "choice_talker");

  ros::NodeHandle n;
  
  char choice;

  ros::Publisher chatter_pub = n.advertise<homework_1::Choice>("Selected_choice", 1000); 

  puts("Select which part of the message do you want to show <a/e/n/c>: ");
  puts("--------------------------------------------------------------");

  while(ros::ok()){
    
    homework_1::Choice msg;


    choice = getch();
    ROS_INFO("\nChoice: %c", choice);

    msg.choice = choice;
    chatter_pub.publish(msg);

    ros::spinOnce();

  }

  return 0;
}

