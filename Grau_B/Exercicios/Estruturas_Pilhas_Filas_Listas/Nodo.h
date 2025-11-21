template <typename T>
class Nodo{
private:
    T tamanho;
    Nodo<T>* proximo;
    Nodo<T>* anterior;

public:

    Nodo(T tamanho);//Construtor com parametros

    ~Nodo();//Destrutor


    void setAnterior(Nodo<T>* nodoAnterior);//Seta o nodo anterior(que pega informacao de tras)
    Nodo<T>* getAnterior();//Pega o tamanho do nodo anterior
    
    void setProximo(Nodo<T>* proximoNodo);//Seta o proximo nodo(que pega informacao da frente)
    Nodo<T>* getProximo();//Pega o tamanho do proximo nodo

    const T& getValor() const;

};

template <typename T>
Nodo<T>::Nodo(T tamanho){
    this->tamanho = tamanho;
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
const T& Nodo<T>::getValor() const{
    return this->tamanho;
}
