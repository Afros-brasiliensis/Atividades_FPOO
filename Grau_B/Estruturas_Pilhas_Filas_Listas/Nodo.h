template <typename T>
class Nodo{
private:
    T valor;
    Nodo<T>* proximo;
    Nodo<T>* anterior;

public:

    Nodo(T valor);//Construtor com parametros

    ~Nodo();//Destrutor


    void setAnterior(Nodo<T>* nodoAnterior);//Seta o nodo anterior(que pega informacao de tras)
    Nodo<T>* getAnterior();//Pega o valor do nodo anterior
    
    void setProximo(Nodo<T>* proximoNodo);//Seta o proximo nodo(que pega informacao da frente)
    Nodo<T>* getProximo();//Pega o valor do proximo nodo

    T getValor();

};

template <typename T>
Nodo<T>::Nodo(T valor){
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

template <typename T>
Nodo<T>::~Nodo(){}

template <typename T>
void Nodo<T>::setProximo(Nodo<T>* proximoNodo){
    this->proximo = proximoNodo;
}
template <typename T>
Nodo<T>* Nodo<T>::getProximo(){
    return this->proximo;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo<T>* nodoAnterior){
    this->anterior = nodoAnterior;
}
template <typename T>
Nodo<T>* Nodo<T>::getAnterior(){
    return this->anterior;
}

template <typename T>
T Nodo<T>::getValor(){
    return this->valor;
}
