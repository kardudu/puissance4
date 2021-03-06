#include <iostream>
//#include "puissance.hpp" // for eclipse
#include "Puissance4.h"
//#include <libltdl/lt_system.h>


#ifdef __unix__

#include "ServerSocket.h"

using namespace std;


struct Joueur {
    string nom;
    char pion;
} joueur[2];

void player_join_ent(ServerSocket s_socket,Puissance4 jeu) {
    string nom_joueur;
    ServerSocket c_socket[2];
    for (int i = 0; i < 2; ++i) {
        s_socket.accept(c_socket[i]);
//        c_socket[i] >> joueur[i].nom;
//        joueur->pion = jeu.get_pion(i);
    }
    cout << joueur[1].pion<<endl;
    cout << joueur[1].pion<<endl;

}

/*bool player_join(int &tcp_client_sock, char pion) {
    vector<char> client_msg_buffer(buffer_len);
    vector<char> server_msg_buffer(buffer_len);
    int i = 0;

    ssize_t status = 0;
    string nom;
    do {
        status = tcp_client_sock >> nom;
        // checking for errors
        if (status == -1) {
            perror("erreur recv : ");
            return false;
        }
        else if (status == 0) {
            cout << "status 0" << endl;
        }
        else {
            nom.append(client_msg_buffer.begin(), client_msg_buffer.end());
        }
        *//* enlever les bytes non necessaire au string recu
        * param[in] string str : message client a "nettoyer"
        * return string s : cleaned msg
        *//*

    } while (status == client_msg_buffer.size());
    string s;
    for (auto car : nom) {
        if (isprint(car)) {
            s += car;
        }
    }
    cout << "s : " << s << endl;

    // nom et affectation pion joueur
    //memcpy(&joueur[i].nom,&client_msg_buffer,buffer_len);
    joueur[i].pion = pion;
    joueur[i].nom = nom;
    cout << "joueur no " << i + 1 << joueur[i].nom << endl;
    cout << "pion :" << pion << endl;
    i++;
    cout << "nom size : " << nom.size() << endl;

    server_msg_buffer.clear();
    server_msg_buffer.push_back(pion);
    status = send(tcp_client_sock, &pion, server_msg_buffer.size(), 0);
    //checking for errors
    if (status == -1) {
        perror("erreur send : ");
        exit(1);
    }
    else {
        cout << server_msg_buffer.data() << endl;
        return true;
    }
}*/

int main() {
    //game vars
    Puissance4 jeu;
    srand((unsigned int) (time(0)));
    string grille = jeu.get_grille();
    int xPos;
    for (auto i=0 ;i<7;i++) {

        int k;
        cin >>k;
        jeu.test(k);
        jeu.afficher_grille();
    }

    jeu.afficher_grille();
    srand((unsigned int) (time(0)));

    cout << "grille size: "<< grille.size() << endl;
    cout << "jeu.get grille size : "<<jeu.grille_size() << endl;


/*    //sock vars
    sockaddr_in tcp_server_addr;
    sockaddr_in tcp_client_addr;
    socklen_t tcp_server_addr_len = sizeof(tcp_server_addr);
    socklen_t tcp_client_addr_len = sizeof(tcp_client_addr);
    int tcp_server_sock, status;
    char server_ip[INET_ADDRSTRLEN];
    //creation socket
    tcp_server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_server_sock == -1) {
        perror("erreur creation socket : ");
        exit(1);
    }
        // initialisaton sock addr
        memset(&tcp_server_addr, 0, tcp_server_addr_len);
        tcp_server_addr.sin_family = AF_INET;
        tcp_server_addr.sin_port = htons(35000); // ask the OS to assign the port
        tcp_server_addr.sin_addr.s_addr = INADDR_ANY;

        int optVal = 1;
        setsockopt(tcp_server_sock, SOL_SOCKET, SO_REUSEADDR, &optVal,
                   sizeof(int));
        //binding
        status = bind(tcp_server_sock, (sockaddr *) &tcp_server_addr,
                      tcp_server_addr_len);
        if (status == -1) {
            perror("erreur bind :");
            exit(1);
        }
        // listening les clients qui se connectent
        listen(tcp_server_sock, 1);
        // info server sock cree
        inet_ntop(AF_INET, &tcp_server_addr.sin_addr, server_ip, sizeof(server_ip));
        if (server_ip == NULL) {
            perror("info sock non recu :");
            exit(1);
        }
        else {
            cout << "adresse : " << server_ip;
            cout << " port :" << ntohs(tcp_server_addr.sin_port) << endl;
        }

        int tcp_client_sock[2];
        tcp_client_sock[0] = -1;
        tcp_client_sock[1] = -1;
        TCPStream *client_sd = NULL;
        TCPAcceptor *sock_acceptant = NULL;
        sock_acceptant = new TCPAcceptor();
        if (sock_acceptant->start()== 0){
        auto i = 1;
            while (i < 2 ){

            client_sd= sock_acceptant->accept();
                auto  status = player_join_net(client_sd,jeu.get_pion(i));
            i++;
                cout << "player join status : " + status<<endl;
            }
        }*/

    ServerSocket s_socket(30000);

    //accepter les deux joueurs
    player_join_ent(s_socket,jeu);
// got two players
/*//game handleling sous progr
    if (
            close(tcp_server_sock)
            == -1) {
        perror("erreur fermeture server socket : ");
        exit(1);
    }

    for (
            int i = 0;
            i < 2; i++) {
        cout << "nom du joueur no " << i + 1 << " : " <<
        endl;
        getline(cin, joueur[i]
                .nom);
        joueur[i].
                pion = jeu.get_pion(i);
    }
    for (
            int i = 0;
            i < 2; i++) {
        cout << joueur[i].nom << " : " << joueur[i].pion <<
        endl;
    }
    int k = 0;
    int j = rand() % 2;
// first to play
    cout << joueur[j].nom << " commence le jeu " <<
    endl;
    do {
        cout << "mettre pion :" <<
        endl;
        cin >>
        xPos;

        while (!jeu.
                placer_pion(xPos, joueur[j]
                .pion)) {
            cout << "colonn pleine ou < 0 ou >6 : ";
            cin >>
            xPos;
        }
        cout << "winner : " << jeu.
                winner(xPos)
        <<
        endl;
        jeu.

                afficher_grille();

        k++;
//gestion tour
        j == 0 ? j++ : j--;
    } while (k < 40);// while no winner*/

    return 0;
}

#elif defined(_WIN32_WINNT) || defined(__WINDOWS__)

#include <WS2tcpip.h> //inet_ntop,INET_ADDRSTRLEN functions

using namespace std;
const int buffer_len = 16;

struct Joueur {
    string nom;
    char pion;
} joueur[2];

bool player_join(SOCKET &tcp_client_sock, char pion) {
    vector<char> client_msg_buffer(buffer_len);
    vector<char> server_msg_buffer(buffer_len);
    int i = 0;
    // vider le buffer de msg clients
    //memset(&client_msg_buffer,0,client_msg_buffer.size());
    int status = 0;
    string nom;
        status = recv( tcp_client_sock, client_msg_buffer.data(),
                client_msg_buffer.size(), 0);
        // checking for errors
        if (status == -1) {
            perror("erreur recv : ");
            return false;
        }
        else if (status == 0) {
            cout << "status 0" << endl;
        }
        else {
            nom.append(client_msg_buffer.begin(), client_msg_buffer.end());
        }
        /* enlever les bytes non necessaire au string recu
        * param[in] string str : message client a "nettoyer"
        * return string s : cleaned msg
        */

    string s;
    for (auto i : nom) {
        if (isalnum(i)) {
            s += i;
        }
    }
    cout << "s : " << s << endl;

    // nom et affectation pion joueur
    //memcpy(&joueur[i].nom,&client_msg_buffer,buffer_len);
    joueur[i].pion = pion;
    joueur[i].nom = nom;
    cout << "joueur no " << i + 1 << joueur[i].nom << endl;
    cout << "pion :" << pion << endl;
    i++;
    cout << "nom size : " << nom.size() << endl;

    server_msg_buffer.clear();
    server_msg_buffer.push_back(pion);
    status = send(tcp_client_sock, &pion, server_msg_buffer.size(), 0);
    //checking for errors
    if (status == -1) {
        perror("erreur send : ");
        exit(1);
    }
    else {
        cout << server_msg_buffer.data() << endl;
        return true;
    }
}

int main() {
    //game vars
    Puissance4 jeux;
    jeux.init_jeux();
    srand(int(time(0)));
    vector<vector<char> > grille = jeux.GetPlateau();
    int xPos;
    jeux.afficher_plateau();
    srand(int(time(0)));

    //sock vars
    WSADATA WSAData;
    SOCKET tcp_server_sock;
    SOCKADDR_IN tcp_server_addr;
    SOCKADDR_IN tcp_client_addr;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    int tcp_server_addr_len = sizeof(tcp_server_addr);
    int tcp_client_addr_len = sizeof(tcp_client_addr);
    int status;
    //creation socket
    tcp_server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_server_sock == SOCKET_ERROR) {
        perror("erreur creation socket : ");
        exit(1);
    }
    // initialisaton sock addr
    memset(&tcp_server_addr, 0, tcp_server_addr_len);
    tcp_server_addr.sin_family = AF_INET;
    tcp_server_addr.sin_port = htons(35000);
    tcp_server_addr.sin_addr.s_addr = INADDR_ANY;
    //Allows other sockets to bind() to this port, unless there is an active listening socket bound to the port already.
    //This enables you to get around those "Address already in use" error messages when you try to restart your server after a crash.
    int optVal = 1;
    setsockopt(tcp_server_sock, SOL_SOCKET, SO_REUSEADDR, (char *) &optVal,sizeof(int));
    //binding
    status = bind(tcp_server_sock, (sockaddr *) &tcp_server_addr,
            tcp_server_addr_len);
    if (status == -1) {
        perror("erreur bind :");
        exit(1);
    }
    // listening les clients qui se connectent
    listen(tcp_server_sock, 1);
    // info server sock cree
    if (getsockname(tcp_server_sock, (sockaddr*)&tcp_server_addr, &tcp_server_addr_len)) {
        perror("info sock non recu :");
        exit(1);
    }
    else {

        cout << "adresse : " << inet_ntoa(tcp_server_addr.sin_addr);
        cout << " port :" << ntohs(tcp_server_addr.sin_port) << endl;

    }

    int tcp_client_sock[2];
    tcp_client_sock[0] = -1;
    tcp_client_sock[1] = -1;
    //accepter les deux joueurs
    for (int i = 0; i < 2; i++) {
        while (tcp_client_sock[i] == -1) {
            tcp_client_sock[i] = accept(tcp_server_sock,
                    (sockaddr *) &tcp_client_addr, &tcp_client_addr_len);

            //if accept fails
            if (tcp_client_sock[i] == -1) {
                cout << "joueur " << i + 1 << "non accepte. ";
                perror("erreur : ");

            }
            else if (!player_join(tcp_client_sock[i], jeux.getPion(i))) {
                tcp_client_sock[i] = -1;
                cout << "message recu incorrect ! " << endl;
                exit(1);
            }
        }
    }
    // got two players
    //game handleling sous progr
    if (closesocket(tcp_server_sock) == -1) {
        perror("erreur fermeture server socket : ");
        exit(1);
    }

    for (int i = 0; i < 2; i++) {
        cout << "nom du joueur no " << i + 1 << " : " << endl;
        getline(cin, joueur[i].nom);
        joueur[i].pion = jeux.get_pion(i);
    }
    for (int i = 0; i < 2; i++) {
        cout << joueur[i].nom << " : " << joueur[i].pion << endl;
    }
    int k = 0;
    int j = rand() % 2;
    // first to play
    cout << joueur[j].nom << " commence le jeu " << endl;
    do {
        cout << "mettre pion :" << endl;
        cin >> xPos;

        while (!jeux.placer_pion(xPos, joueur[j].pion)) {
            cout << "colonn pleine ou < 0 ou >6 : ";
            cin >> xPos;
        }
        cout << "winner : " << jeux.winner(xPos) << endl;
        jeux.afficher_grille();
        k++;
        //gestion tour
        j == 0 ? j++ : j--;
    } while (k < 40); // while no winner
    return 0;
}
#endif
