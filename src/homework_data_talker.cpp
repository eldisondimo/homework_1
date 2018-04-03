
#include "ros/ros.h"
// Have to include the message previously created
#include "homework_1/Data.h"
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{

  srand(time(NULL));

  // Select a random name
  const char *list[] = {"Andrea" , "Eldison", "Marco", "Luca", "Antonio", "Alessia", "Marta"};
  std::vector<std::string> names(list, list + 7);

  // Select a random course
  const char *courses[6] = {"Ingegneria e Scienze Informatiche", "Biotecnologie", "Matematica", "Lettere", "Lingue", "Economia"};

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  // Create the topic "Message_data" 
  ros::Publisher chatter_pub = n.advertise<homework_1::Data>("Message_data", 1000);

  // Talker publishes 1 time per sec
  ros::Rate loop_rate(1);

  // Until cltr-c isn't pressed yet
  while (ros::ok())
  {
    /**
     * This is a message object.
     */
    homework_1::Data msg;
    

    msg.eta = (rand()%40)+19;
    msg.nome = names[rand()%7];
    msg.corso_laurea = courses[rand()%6];

    ROS_INFO("\nInvio\nNome: %s\nEta':%d\nCorso di laurea: %s\n", msg.nome.c_str(), msg.eta, msg.corso_laurea.c_str());

    // publishing the message
    chatter_pub.publish(msg);


    ros::spinOnce();

    // wait until 1 sec isn't passed
    loop_rate.sleep();

  }

  return 0;
}
