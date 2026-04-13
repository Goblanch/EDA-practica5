#include <iostream>
#include <memory>
#include <vector>
#include "Producto.h"
#include "Arbol.h"
#include "GestorInventario.h"

int main() {
    // -- 1. Datos del inventario -------------------------------------------
    std::vector<Producto> inventario = {
        //  Codigo       Nombre                          Categoria         Precio   Stock
        { "PRD-004",  "Teclado Mecanico RGB",            "Perifericos",    89.99,   45  },
        { "PRD-002",  "Monitor Full HD 24\"",             "Pantallas",     199.99,   20  },
        { "PRD-007",  "Raton Inalambrico",                "Perifericos",    34.50,   80  },
        { "PRD-001",  "Auriculares Bluetooth 5.0",        "Audio",          59.95,   60  },
        { "PRD-005",  "Webcam 1080p Streaming",           "Video",          49.00,   35  },
        { "PRD-009",  "Hub USB-C 7 Puertos",              "Conectividad",   27.99,  110  },
        { "PRD-003",  "SSD NVMe 1 TB",                    "Almacenamiento", 109.00,  55  },
        { "PRD-008",  "Alfombrilla XL Gaming",            "Perifericos",    19.95,  150  },
        { "PRD-006",  "Lampara LED de Escritorio",        "Iluminacion",    22.50,   70  },
        { "PRD-010",  "Soporte Portatil Ajustable",       "Ergonomia",      15.99,   90  }
    };

    // -- 2. Creacion del ABB -----------------------------------------------
    std::shared_ptr<IArbol> arbol = std::make_shared<Arbol>();
    GestorInventario        gestor(arbol);

    gestor.crearInventarioABB(inventario);
    gestor.mostrarInventario();

    // -- 3. Calculo de Nivel / Profundidad ------------------------------------
    std::cout << "\n+============================================================================+\n";
    std::cout << "|                        CONSULTAS DE NIVEL                                 |\n";
    std::cout << "+============================================================================+\n";
    gestor.consultarNivel("PRD-004");   // Raiz        -> nivel 0
    gestor.consultarNivel("PRD-007");   // Intermedio  -> nivel 1
    gestor.consultarNivel("PRD-010");   // Hoja        -> nivel 3
    gestor.consultarNivel("PRD-099");   // Inexistente -> -1

    // -- 4. Arbol Espejo ------------------------------------------------------
    gestor.mostrarEspejo();

    std::cout << "\n----------------------------------------------------------------------------\n";
    std::cout << "  Fin del programa EDA_P5GA1_E1_26\n\n";

    return 0;
}