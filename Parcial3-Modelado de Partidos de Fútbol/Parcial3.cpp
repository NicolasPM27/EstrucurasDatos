/*
Fecha: 26-05-2023
Autor: Nicolás Padilla
*/
//--------------------------------------- CLASES DADAS POR EL ENUNCIADO ---------------------------------------
class Jugador
{
protected:
    int m_Numero;          // *
    float m_PosX;          // *
    float m_PosY;          // *
    float m_TamanoTerreno; // *
public:
    Jugador();                             // *
    virtual ~Jugador();                    // *
    float ObtenerDesempenoAtaque() const;  // *
    float ObtenerDesempenoDefensa() const; // *
    float CalcularEfectividadHasta(const Jugador &otro) const;
};
class SituacionDeJuego
{
protected:
    std::vector<Jugador> m_Jugadores;
    float m_TamanoTerreno; // *
public:
    SituacionDeJuego();          // *
    virtual ~SituacionDeJuego(); // *
    struct NodoSecuenciasOptimas
    {
        int ElPaseVieneDesde;
    };
    typedef std::vector<NodoSecuenciasOptimas> SecuenciasOptimas;
    SecuenciasOptimas ObtenerSecuenciasOptimas(int numero, bool esAtaque) const;
    struct SecuenciaOptima
    {
        std::vector<int> Secuencia;
        float ProbabilidadFinal;
        bool TodosLosJugadores;
    };
    SecuenciaOptima ObtenerSecuenciaOptima(int numero, bool esAtaque) const;
};

//---------------------------------------PUNTO 1---------------------------------------
/*
Método para calcular la efectividad del pase de balón entre dos jugadores teniendo en cuenta la formula
dada en el enunciado del parcial.
Pasos a seguir:
1. Se crea un objeto de tipo Jugador llamado a y otro llamado b.
2. Se calcula la distancia entre los dos jugadores con la formula dada en el enunciado.
3. Se calcula la efectividad del pase de balón con la formula dada en el enunciado.
4. Se retorna la efectividad del pase de balón.
*/
float Jugador::CalcularEfectividadHasta(const Jugador &otro) const
{
    Jugador a = *this;
    Jugador b = otro;
    float efectividad = 0;
    largo = 133;
    efectividad = 1 - (sqrt(pow((b.m_PosX - a.m_PosX), 2) + pow((b.m_PosY - a.m_PosY), 2)) / largo);
    return efectividad;
}

//---------------------------------------PUNTO 2---------------------------------------
/*
Método para generar todas las sec de pases optimas para todos los demas jugadores
Pasos a seguir:
1. Se crea una matriz de distancias entre jugadores.
2. Se calculan las distancias entre los jugadores utilizando el método CalcularEfectividadHasta de la clase Jugador.
3. Se calculan las sec optimas de pases utilizando el algoritmo de Dijkstra.
4. Se construyen las sec optimas de pases para los demas jugadores.
*/
SituacionDeJuego::SecuenciasOptimas SituacionDeJuego::ObtenerSecuenciasOptimas(int numero, bool esAtaque) const
{
    // Crear una matriz de distancias entre jugadores
    int numJugadores = m_Jugadores.size();
    std::vector<std::vector<float>> distancias(numJugadores, std::vector<float>(numJugadores));

    // Calcular las distancias entre los jugadores utilizando el método CalcularEfectividadHasta de la clase Jugador
    for (int i = 0; i < numJugadores; i++)
    {
        for (int j = 0; j < numJugadores; j++)
        {
            if (i != j)
            {
                distancias[i][j] = m_Jugadores[i].CalcularEfectividadHasta(m_Jugadores[j]);
            }
            else
            {
                distancias[i][j] = 0.0f; // La distancia de un jugador a sí mismo es cero
            }
        }
    }

    // Algoritmo de Dijkstra para encontrar las sec óptimas de pases
    int origen = numero - 1; // Índice del jugador actual
    std::vector<float> costos(numJugadores, std::numeric_limits<float>::max());
    std::vector<bool> visitados(numJugadores, false);
    std::vector<int> previo(numJugadores, -1);

    costos[origen] = 0.0f;

    for (int i = 0; i < numJugadores - 1; i++)
    {
        int u = -1;
        float menorCosto = std::numeric_limits<float>::max();

        // Buscar el jugador no visitado con el costo mínimo
        for (int j = 0; j < numJugadores; j++)
        {
            if (!visitados[j] && costos[j] < menorCosto)
            {
                u = j;
                menorCosto = costos[j];
            }
        }

        if (u == -1)
            break;

        visitados[u] = true;

        // Actualizar los costos de los jugadores vecinos no visitados
        for (int v = 0; v < numJugadores; v++)
        {
            if (!visitados[v] && distancias[u][v] > 0 && costos[u] + (1 - distancias[u][v]) < costos[v])
            {
                costos[v] = costos[u] + (1 - distancias[u][v]);
                previo[v] = u;
            }
        }
    }

    // Construir las sec óptimas de pases para los demás jugadores
    SecuenciasOptimas sec;

    for (int i = 0; i < numJugadores; i++)
    {
        if (i != origen)
        {
            int jugadorActual = i;
            SecuenciaOptima secuenciaOptima;

            // Construir la secuencia óptima de pases retrocediendo desde el jugador actual
            while (jugadorActual != -1)
            {
                secuenciaOptima.Secuencia.push_back(jugadorActual + 1); // Agregar el número de jugador (se suma 1 porque los números de jugadores comienzan desde 1)
                jugadorActual = previo[jugadorActual];
            }

            std::reverse(secuenciaOptima.Secuencia.begin(), secuenciaOptima.Secuencia.end()); // Invertir la secuencia para que esté en el orden correcto

            secuenciaOptima.ProbabilidadFinal = 1 - costos[i];
            secuenciaOptima.TodosLosJugadores = !esAtaque; // Dependiendo del valor de esAtaque, establecer si es para todos los jugadores o no

            sec.push_back(secuenciaOptima);
        }
    }

    return sec;
}

//---------------------------------------PUNTO 3---------------------------------------
/*
Método para identificar al jugador con mayor desempeño en la estrategia y encontar la ruta de mayor efectividad de pase, la probabilidad final e informar si la jugada involucró a todos los jugadores
Pasos a seguir:
1. Se obtienen las secuencias optimas de pases para el jugador actual.
2. Se identifica al jugador con mayor desempeño.
3. Se construye la secuencia optima de pases para el jugador con mayor desempeño.
4. Se retorna la secuencia optima de pases.
*/
SituacionDeJuego::SecuenciaOptima SituacionDeJuego::ObtenerSecuenciaOptima(int numero, bool esAtaque) const
{
    SecuenciasOptimas secuencias = ObtenerSecuenciasOptimas(numero, esAtaque);
    Jugador mejorJugador;
    float desempeno=0.0f;
    // Encontrar al jugador con mayor desempeño
    if (esAtaque)//si es ataque
    {
        for (int i = 0; i < m_Jugadores.size(); i++)
        {
            if (m_Jugadores[i].obtenerDesempenoAtaque()>desempeno)
            {
                mejorJugador = m_Jugadores[i];
                desempeno = m_Jugadores[i].obtenerDesempenoAtaque();
            }
        }
    }
    else//si es defensa
    {
        for (int i = 0; i < m_Jugadores.size(); i++)
        {
            if (m_Jugadores[i].obtenerDesempenoDefensa()>desempeno)
            {
                mejorJugador = m_Jugadores[i];
                desempeno = m_Jugadores[i].obtenerDesempenoDefensa();
            }
        }
    }
    SecuenciasOptimas sec = secuencias.first;//secuencias de pases
    vector<float> probabilidad = secuencias.second;//probabilidades de pases
    SecuenciaOptima secuenciaOptima; //secuencia optima de pases
    int jActual = m_jugadores[numero].m_numero;  //jugador actual
    bool todos = true;  //todos los jugadores
    while(jActual != numero) {//mientras el jugador actual sea diferente al numero
        secuenciaOptima.Secuencia.insert(secuenciaOptima.Secuencia.begin(), jActual);  //insertar al inicio de la secuencia optima el jugador actual
        if(sec[jActual].ElPaseVieneDesde == -1) todos = false;//si el pase viene desde -1, no todos los jugadores
        jActual = sec[jActual].ElPaseVieneDesde;  //el jugador actual es el pase que viene desde
    }

    secuenciaOptima.Secuencia.insert(secuenciaOptima.Secuencia.begin(), numero); //insertar al inicio de la secuencia optima el numero
    secuenciaOptima.ProbabilidadFinal = probabilidad[mejorJugador];  //probabilidad final es la probabilidad del mejor jugador
    secuenciaOptima.TodosLosJugadores = todos; 

    return secuenciaOptima;  

}