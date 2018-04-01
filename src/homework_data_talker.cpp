
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

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  // Creo un topic Homework_1 sul quale pubblicare messaggi di tipo 'Data' che ho precedentemente creato nella cartella
  // msg
  ros::Publisher chatter_pub = n.advertise<homework_1::Data>("Message_data", 1000);

  // Il talker pubblica il messaggio 1 volta al sec
  ros::Rate loop_rate(1);

  // Finchè non decido di uscire
  while (ros::ok())
  {
    /**
     * This is a message object.
     */
    homework_1::Data msg;
    

    msg.eta = (rand()%40)+19;
    msg.nome = names[rand()%7];
    msg.corso_laurea = "Corso di laurea in Ingegneria e Scienze Informatiche";

    	// stampo le info a terminale
    ROS_INFO("\nInvio\nNome: %s\nEta':%d\nCorso di laurea: %s\n", msg.nome.c_str(), msg.eta, msg.corso_laurea.c_str());

    // pubblico il messaggio
    chatter_pub.publish(msg);


    ros::spinOnce();

    // Fermati finchè non è passato 1 secondo
    loop_rate.sleep();

  }

  return 0;
}
