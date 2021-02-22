#include "../include/server_event_receiver.h"
#include "socket_error.h"

void Server_Event_Receiver::run() {
    while (this->corriendo) {
        std::vector<char> informacion;
        try {
            std::vector<char> informacion = this->protocolo->recibir();
            if (informacion.empty()) {
                this->cerrar();
            } else {
                std::cerr << "comando size:  " << informacion.size() << std::endl;
                Comando *comando = protocolo->deserializarComando(informacion);
                if (comando == nullptr) {
                    this->cerrar();
                } else {
                    this->comandos.aniadir_dato(comando);
                }
            }
        } catch (const SocketError &exc) {
            std::cerr << "error socket";
            std::cout << exc.what() << std::endl;
            this->cerrar();
        } catch (std::exception &exc) {
            std::cerr << "otro error\n";
            std::cout << exc.what() << std::endl;
            this->cerrar();
        } catch (...){
            std::cout << "error desconocido\n";
        }
    }
}

void Server_Event_Receiver::cerrar() {
    this->corriendo = false;
    protocolo->cerrar();
}

bool Server_Event_Receiver::estaCorriendo() {
    return corriendo;
}
