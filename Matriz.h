#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>

namespace TP2{//inicio

template <class tipo>
class Matriz
{
private:

    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    tipo *pMatriz;

public:
    Matriz(int qLinhas, int qColunas);
    ~Matriz();
    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}
    tipo getElemento(int linha, int coluna)const;
    void setElemento(int linha, int  coluna, tipo elemento)const;
    QString getConjunto()const;
    Matriz<tipo>* operator + (Matriz<tipo> const * const mat)const;
    Matriz<tipo>* operator - (Matriz<tipo> const * const mat)const;
    Matriz<tipo>* operator * (Matriz<tipo> const * const mat)const;
    bool operator == (Matriz<tipo> const*const mat)const;
    bool operator != (Matriz<tipo> const*const mat)const;
    Matriz<tipo>* multiplicarPorK(const int k )const;
    bool eMatrizIdentidade()const;
    Matriz<tipo>* potenciacao(int potencia)const;
    Matriz<tipo>* transposta()const;
    bool eTringularSuperior()const;
    bool eTringularInferior()const;
    bool eMatrizSimetrica()const;
    bool eMatrizOrtogonal()const;
    bool eMatrizPermutacao()const;

};



template <class tipo>
Matriz<tipo>::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    pMatriz(0)

{

    if(qLinhas<=0) throw QString("Quantidade de linhas não pode ser menor ou igual a 0");
    if(qColunas<=0) throw QString("Quantidade de colunas não pode ser menor ou igual a 0");
try{
    pMatriz=new tipo [qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");

            }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}
template <class tipo>
Matriz<tipo>::~Matriz()
{
    if(pMatriz) delete[] pMatriz;
}
template <class tipo>
tipo Matriz<tipo>::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos=linha*quantidadeDeColunas+coluna;
    return *(pMatriz+pos);


}
template <class tipo>
void Matriz<tipo>::setElemento(int linha, int  coluna, tipo elemento)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos =  linha*quantidadeDeColunas+coluna;
    *(pMatriz+pos) = elemento;
}
template <class tipo>
QString Matriz<tipo>::getConjunto()const{
    QString saida="";
    for(int linha= 0;linha<getQuantidadeDeLinhas();linha++){
        for(int coluna = 0; coluna<getQuantidadeDeColunas(); coluna++){
            saida+=QString::number(getElemento(linha,coluna));
            saida +="  ";
        }
        saida +="\n";
    }
    return saida;
}
template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator + (Matriz<tipo> const * const mat)const{
    if(quantidadeDeLinhas != mat->getQuantidadeDeColunas() ||
       quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser adicionadas matriz de tomanhos diferentes");
    try{Matriz<tipo> *aux = new Matriz<tipo>(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas;linha++){
            for(int coluna=0; coluna<quantidadeDeColunas;coluna++){
                tipo valor = this->getElemento(linha, coluna)+mat->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
}
    catch(std::bad_alloc&){
        throw QString("Vai compra Memoria");
    }
    catch(QString &erro){
        throw QString ("Matriz auxiliar não criada não podemos adicinar as matrizes");
    }
}
template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator - (Matriz<tipo> const * const mat)const{
    if(quantidadeDeLinhas != mat->getQuantidadeDeColunas() ||
       quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser adicionadas matriz de tomanhos diferentes");
    try{Matriz<tipo> *aux = new Matriz<tipo>(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas;linha++){
            for(int coluna=0; coluna<quantidadeDeColunas;coluna++){
                tipo valor = this->getElemento(linha, coluna)-mat->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
}
    catch(std::bad_alloc&){
        throw QString("Vai compra Memoria");
    }
    catch(QString &erro){
        throw QString ("Matriz auxiliar não criada não podemos adicinar as matrizes");
    }
}

template <class tipo>
bool Matriz<tipo>::operator == (Matriz<tipo> const*const mat)const{
    if(this->quantidadeDeColunas!=mat->quantidadeDeColunas||this->quantidadeDeLinhas!=mat->quantidadeDeLinhas)return false;
    for(int linha = 0; linha<this->quantidadeDeLinhas;linha++){
        for(int coluna = 0;coluna<this->quantidadeDeColunas;coluna++){
            if(this->getElemento(linha,coluna)!=mat->getElemento(linha,coluna)){
                return false;
            }
        }
    }
    return true;
}
template <class tipo>
bool Matriz<tipo>::operator != (Matriz<tipo> const*const mat)const{
    if(this->quantidadeDeColunas!=mat->quantidadeDeColunas||this->quantidadeDeLinhas!=mat->quantidadeDeLinhas)return true;
    for(int linha = 0; linha<this->quantidadeDeLinhas;linha++){
        for(int coluna = 0;coluna<this->quantidadeDeColunas;coluna++){
            if(this->getElemento(linha,coluna)!=mat->getElemento(linha,coluna)){
                return true;
            }
        }
    }
    return false;
}


template <class tipo>
Matriz<tipo>* Matriz<tipo>::multiplicarPorK(int const k )const{
    try{
    Matriz<tipo> *aux=new Matriz<tipo>(this->quantidadeDeLinhas,this->quantidadeDeColunas);


    tipo x;
    for(int linha=0; linha<quantidadeDeLinhas;linha++){
        for(int coluna=0; coluna<quantidadeDeColunas;coluna++){
        x=k*this->getElemento(linha,coluna);
         aux->setElemento(linha,coluna,x);
        }
    }
    return aux;
    }catch(std::bad_alloc){
        throw QString("Vai compra memoria");
    }
}



template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator * (Matriz<tipo> const * const mat)const{
    if(this->quantidadeDeColunas!=mat->quantidadeDeLinhas)throw QString("Operação invalida.");


    Matriz<tipo> *aux=new Matriz<tipo>(mat->quantidadeDeLinhas,mat->quantidadeDeColunas);
    for(int linha=0;linha<mat->quantidadeDeLinhas;linha++){

        for(int coluna=0;coluna<mat->quantidadeDeColunas;coluna++){
            tipo valor=0;
            for(int n=0;n<mat->quantidadeDeLinhas; n++){
                valor+= this->getElemento(linha,n)*mat->getElemento(n,coluna);
            aux->setElemento(linha,coluna,valor);
            }
        }
    }
    return aux;

}
template <class tipo>
bool Matriz<tipo>::eMatrizIdentidade()const{
    if(this->quantidadeDeLinhas!=this->quantidadeDeColunas)return false;

    for(int i=0;i<this->quantidadeDeColunas;i++){
        if(this->getElemento(i,i)!=1){
            return false;
        }
    }
    tipo soma=0;
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0; coluna<this->quantidadeDeColunas;coluna++){
            soma+=this->getElemento(linha,coluna);
        }
    }
    return (soma==this->quantidadeDeColunas);
}
template <class tipo>
Matriz<tipo>* Matriz<tipo>::potenciacao(int potencia)const{

    if(this->quantidadeDeLinhas!=this->quantidadeDeColunas)throw QString("Operação invalida.");

    Matriz<tipo> *aux=new Matriz<tipo>(this->quantidadeDeLinhas,this->quantidadeDeColunas);


    if(potencia==0){
        for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
                if(linha==coluna){
                    aux->setElemento(linha,coluna,1);
                }else{
                    aux->setElemento(linha,coluna,0);
                }
            }
        }
        return aux;
    }

    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            aux->setElemento(linha,coluna,this->getElemento(linha,coluna));
        }
    }

    if(potencia==1){
        return aux;

    }


    if(potencia>1){
        for(int i=1;i<potencia;i++){
        aux= (*aux)*(aux);
        }
    }
    return aux;
}
template <class tipo>
Matriz<tipo>* Matriz<tipo>::transposta()const{
    Matriz<tipo> *mat=new Matriz<tipo>(this->quantidadeDeColunas,this->quantidadeDeLinhas);

    for(int linha=0;linha<this->quantidadeDeColunas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeLinhas;coluna++){
            mat->setElemento(linha,coluna,this->getElemento(coluna,linha));
        }
    }
return mat;
}
template <class tipo>
bool Matriz<tipo>::eTringularSuperior()const{
    if(this->quantidadeDeLinhas!=this->quantidadeDeColunas){return 0;}
    if(this->quantidadeDeColunas==1&&this->quantidadeDeLinhas==1){return false;}

    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(linha>coluna){
                if(this->getElemento(linha,coluna)!=0)return false;
            }
        }
    }
    return true;
}
template <class tipo>
bool Matriz<tipo>::eTringularInferior()const{
    if(this->quantidadeDeLinhas!=this->quantidadeDeColunas)return 0;
    if(this->quantidadeDeColunas==1&&this->quantidadeDeLinhas==1){return false;}
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(linha<coluna){
                if(this->getElemento(linha,coluna)!=0)return false;
            }
        }
    }
    return true;
}
template <class tipo>
bool Matriz<tipo>::eMatrizSimetrica()const{



    if(this->quantidadeDeColunas!=this->quantidadeDeLinhas){return false;}
    if(this->quantidadeDeColunas==1&&this->quantidadeDeLinhas==1){return false;}
    int x=true;
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(this->getElemento(linha,coluna)!=this->getElemento(coluna,linha)){x=false;}
        }
    }
    return x;
}
template <class tipo>
bool Matriz<tipo>::eMatrizOrtogonal()const{
    bool x=true;//testei se a matriz A*AŦ(OBJETO) E IGUAL A MATRIZ IDENTIDADE
    try{
    TP2::Matriz<tipo> *aux=new TP2::Matriz<tipo>(this->quantidadeDeLinhas, this->quantidadeDeColunas);

    for(int linha=0;linha<this->quantidadeDeColunas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeLinhas;coluna++){
            aux->setElemento(linha,coluna,this->getElemento(linha,coluna));
        }
    }


    aux= aux->operator *(aux->transposta());


    Matriz<tipo> *identidade=new Matriz<tipo>(this->quantidadeDeLinhas,this->quantidadeDeColunas);
    //criei uma matriz identdade
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
           if(linha==coluna){
               identidade->setElemento(linha,coluna,1);

           }else{
              identidade->setElemento(linha,coluna,0);
           }
        }
    }


    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(aux->getElemento(linha,coluna)!=identidade->getElemento(linha,coluna)){
                x=false;
            }
        }
    }
    delete identidade;//DELETEI A IDENTIDADE QUE EU CRIEI
    delete aux;//DELETEI A MATRIZ AUX
    }catch(std::bad_alloc&){
        throw QString("Maquina sem memoria.");
    }


    return x;//RETORNEI O VALOR LOGICO DO TESTE

 }
template<class tipo>
bool Matriz<tipo>::eMatrizPermutacao()const{

    bool x=true;
    try{
    TP2::Matriz<tipo> *aux=new TP2::Matriz<tipo>(this->quantidadeDeLinhas, this->quantidadeDeColunas);

    for(int linha=0;linha<this->quantidadeDeColunas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeLinhas;coluna++){
            aux->setElemento(linha,coluna,this->getElemento(linha,coluna));
        }
    }


    aux= aux->operator *(aux->transposta());


    Matriz<tipo> *identidade=new Matriz<tipo>(this->quantidadeDeLinhas,this->quantidadeDeColunas);
    //criei uma matriz identdade
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
           if(linha==coluna){
               identidade->setElemento(linha,coluna,1);

           }else{
              identidade->setElemento(linha,coluna,0);
           }
        }
    }

    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(aux->getElemento(linha,coluna)!=identidade->getElemento(linha,coluna)){
                x=false;
            }
        }
    }
    delete aux;//DELETEI AUX
    delete identidade;//DELETEI A IDENTIDADE QUE EU CRIEI

}catch(std::bad_alloc&){
    throw QString("maquina sem memoria.");}
    return x;//RETORNEI O VALOR LOGICO DO TESTE

 }

}//fim

#endif // MATRIZ_H
