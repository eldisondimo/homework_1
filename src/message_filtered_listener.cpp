#include "ros/ros.h"
#include "homework_1/Data.h"
#include "homework_1/Choice.h"
#include <string>


char choice = 'a';

void printMessageCallback(const homework_1::Data::ConstPtr& msg)
{

  switch(choice){
    case 'a': ROS_INFO("\nReceived:\nNome: %s\nCorso di Laurea: %s\nEta': %d",msg->nome.c_str(), msg->corso_laurea.c_str(), msg->eta);
              break;

    case 'c': ROS_INFO("\nReceived:\nCorso di Laurea: %s\n", msg->corso_laurea.c_str());
              break;

    case 'n': ROS_INFO("\nReceived:\nNome: %s\n", msg->nome.c_str());
              break;

    case 'e': ROS_INFO("\nReceived:\nEta': %d\n",msg->eta);
              break;

    default:  ROS_INFO("\nReceived: command unknown. Printing all the data next"); 
              choice = 'a';
              break;
  }

}

void getChoiceCallback(const homework_1::Choice::ConstPtr& msg){

  choice = msg->choice;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub_data = n.subscribe("Message_data", 1000, printMessageCallback);
  ros::Subscriber sub_selection = n.subscribe("Selected_choice", 1000, getChoiceCallback);

  ros::spin();

  return 0;
}

