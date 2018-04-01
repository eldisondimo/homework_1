# homework_1
Primo homework per il corso "Laboratorio cyberfisico" su ROS.

Lo scopo dell'homework è stato essenzialmente creare 3 nodi ROS con le seguenti prorpietà:
- Un nodo pubblica ogni secondo (loop rate = 1Hz) un messaggio (Data.msg) sul topic "Message_data" contenente 3 campi:
nome e corso di laurea, di tipo string, e l'età, un intero di 8 bit.
- Un nodo che rimane in attesa di un comando, un carattere, e che ,una volta letto, lo pubblica attraverso un nuovo messaggio (Choice.msg) su un nuovo topic ( "Selected_choice" )
- Un terzo nodo che si iscrive sia al topic "Message_data" che al "Selected_choice". Legate ai due topic abbiamo quindi due funzioni di callback: getChoice e printMessage. 
La prima salva il carattere ottenuto dal messaggio Choice.msg in una variabile globale ;
La seconda stampa il campo di Data.msg relativo al carattere ricevuto. In caso riceva un carattere non definito, stampa un messaggio d'errore e continua con la visualizzazione di tutti e 3 i campi.

N.B.: Per acquisire il carattere senza attendere l'invio è stata utilizzata la funzione getch() che sfrutta la libreria termios.h
