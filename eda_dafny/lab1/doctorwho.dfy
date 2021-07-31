include "predicados_doctorwho.dfy" //sustituye aqui por tu fichero
include "specFunctions.dfy"

//1.Especificación de un metodo que determine si todos los elementos de un vector son distintos de un elemento dado

method mdistintosDe(v:array<int>, x:int) returns (b:bool)
//requires true
ensures b==distintosDe(v[0..v.Length],x)

//2. Especificación de un método que determine si todos los elementos de un vector son positivos.
method mpositivos(v:array<int>) returns (b:bool)
//requires true
ensures b==positivos(v[0..v.Length])

//3. Especificación de un método que determine si todos los elementos de un vector son iguales.
method miguales(v:array<int>) returns (b:bool)
//requires true
ensures b==iguales(v[0..v.Length])

//4. Especifica un método mparesEntreA que 
//determine si todos los elementos de un array de enteros contenidos entre dos posiciones dadas c (incluida) y f (excluida) son pares. 
//Se considera que el intervalo [c, f) es vacio cuando c = f. 
//Recuerda, en la precondición has de colocar las condiciones que deben cumplir c y f,
//y también los elementos del array (usa el predicado positivos). 
method mparesEntreA(c: int, f: int, v: array<int>) returns (b: bool)
requires 0<= c < f < v.Length
requires positivos(v[c..f])
ensures b==forall k::c <= k < f < v.Length ==> esPar(v[k])

//5. Especifica un método mparesEntreC que determine si todos los elementos 
//de un array de enteros contenidos entre dos posiciones dadas c (incluida) y f (incluida) son pares.
//Se considera que el intervalo [c, f] es vacío cuando c = f+1.
//Recuerda, en la precondición has de colocar las condiciones que deben cumplir c y f,
//y también los elementos del array (en este caso no utilices el predicado positios).
method mparesEntreC(c: int, f: int, v: array<int>) returns (b: bool)
requires 0 <= c < c+1 < f < v.Length
ensures forall k::c <= k <= f < v.Length ==> v[k] >= 0 && esPar(v[k])

//6. Especifica un método mprimerCero que dado un array de enteros devuelva la posición en la que se encuentra 
//el primer elemento igual a 0, y en caso de no haber ninguno devuelva la longitud del array.
//Utiliza el predicado esPrimerCero.
method mprimerCero(v: array<int>, x: int) returns (b: bool)
requires 0 <= x < v.Length
ensures b==esPrimerCero(v[0..v.Length], x)

//7. Especifica un método mprimerNegativo que dado un array de enteros 
//devuelva un booleano que indica si existe algún valor negativo en el array,
//y en caso de haberlo la posición más a la izquierda que contiene un valor negativo. 
method mprimerNegativo(v: array<int>) returns (b: bool, i: int)
ensures b == (exists k:: 0 <= k < v.Length && v[k] < 0)
ensures (b && 0 <= i < v.Length && v[i] < 0 && forall x:: 0 <= x < v.Length ==> v[x] >= 0)
//ensures !b || (b && 0 <= i < v.Length && v[i] < 0 && forall x:: 0 <= x < i < v.Length ==> v[x] >= 0)
//No se mira el !b ya que se consuta,, solo se mira el caso en el qu b es cierto
//Segunda parte no hace falta hablar i 
//Solo consultarás i si b es verdadero, de ahí que nno haga falta consultar !b

//8.Especifica un metodo que calcule una posicion del maximo de un vector de enteros
method mmaximo(v: array<int>) returns (i: int) 
ensures (0 <= i < v.Length && forall x:: 0 <= x < v.Length ==> v[x] <= v[i])


//9. Especifica un metodo que calcule la posicion de la aparicion mas a la izquierda  del maximo de un vector de enteros
method mprimerMaximo(v:array<int>) returns (i:int)
ensures (0 <= i < v.Length && forall x:: 0 <= x < i ==> v[x] < v[i])


//10. Especifica un metodo que calcule la posicion de la aparicion mas a la derecha  del maximo de un vector de enteros
method multimoMaximo(v:array<int>) returns (i:int)
ensures (0 <= i < v.Length && forall x:: i <= x < v.Length ==> v[x] < v[i])


//11. Especificación de un metodo que calcule el cociente y el resto de la division de naturales.
method mdivide (a: int, b:int) returns (c:int,r:int) //O(mcd(a,b))
requires a>=0 && b>0
ensures a==b*c+r && 0<=r<b


//12.Especifica un metodo que calcule la raiz entera de un entero positivo
method mraiz(n:int) returns (r:int) 
ensures n==r*r

//13.Especifica un metodo que calcule la potencia de 2 elevado a un numero natural dado
function potencia(b: int, e: nat) : int
decreases e;
{
 if (e==0) then 1 else b*potencia(b,e-1)

}

method mpotencia(n: int) returns (pot: int)
//Especifica
requires n>=0
ensures pot==potencia(2,n)

//14.Especifica un metodo que  calcula la suma de los elementos de un array de enteros
method msuma(v:array<int>) returns (suma:int) //de izquierda a derecha
//ensures  suma==SumS(v[0..v.Length])
ensures suma==SumV(v, 0, v.Length)


//15.Especifica un metodo que cuenta el numero de pares de un array de enteros positivos
function ContarPares(s : seq<int>):nat
 decreases s;
 requires forall i:: 0<=i<|s| ==> s[i]>=0
 {
    if s==[] then 0
    else (if esPar((s[|s|-1])) then 1 else 0)+ContarPares(s[..|s|-1])
}

method mpares(v:array<int>) returns (n:int)
requires positivos(v[0..v.Length])
ensures  n==ContarPares(v[0..v.Length])


//16.Especifica un metodo que indica si un vector es Gaspariforme (ejercicio 8 de los apuntes)

method mgaspariforme(v:array<int>) returns (b:bool)
 ensures forall i:: 0 <= i < v.Length ==> SumV(v, 0, i)>=0
 ensures SumS(v[0..v.Length]) >= 0


//17.Especifica un método que indica si hay la misma cantidad de numeros pares que de impares en un array de enteros positivos

method mmismaParidad(v:array<int>) returns (b:bool)
requires positivos(v[0..v.Length])
ensures  b==(ContarPares(v[0..v.Length]) == ContarInPares(v[0..v.Length]))
function ContarInPares(s : seq<int>):nat
 decreases s;
 requires forall i:: 0<=i<|s| ==> s[i]>=0
 {
    if s==[] then 0
    else (if !esPar((s[|s|-1])) then 1 else 0)+ContarInPares(s[..|s|-1])
}
//OTRA FORMA
//ensures  b==(ContarPares(v[0..v.Length]) == v.Length - ContarInPares(v[0..v.Length]) )

//18. Especifica un metodo que positiviza un vector de enteros, lo cual consiste en reemplazar los valores
// negativos por cero respetando el resto de valores
method mpositivizar(v:array<int>)
modifies v
ensures forall k::0<=k<v.Length && old(v[k])<0 ==> v[k]==0 &&
        forall k::0<=k<v.Length && old(v[k])>=0 ==> v[k]==old(v[k])


//19. Especifica un metodo que en un vector de enteros reemplaza todas las apariciones de un 
//numero dado x por otro y respetando el resto de valores
method mreemplazar(v: array<int>, x: int, y: int)
modifies v
ensures forall k::0 <= k < v.Length && old(v[k]) == x ==> v[k] == y &&
        forall k::0 <= k < v.Length && old(v[k]) != x ==> v[k] == old(v[k])


//20. Especifica un metodo que dado un vector v de enteros devuelva otro vector w con su imagen especular 
method mespecular(v:array<int>, w:array<int>)
modifies w
requires v.Length == w.Length
ensures forall k:: 0 <= k < v.Length ==> v[k] == w[(v.Length -1) - k]
