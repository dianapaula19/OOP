## Proiect 1: Clasa Polinom Dinamic (Tema 14)

### Descriere:

Reprezentat ca lista inlantuita (ca polinoame rare, prin lista perechilor (coeficient,exponent), ordonata crescator dupa exponent, si
nu neaparat cu exponentii consecutivi.
Cerintele sunt aceleași ca la Tema 13, adaptate pentru liste alocate dinamic.

## Proiect 2: Magazin (Tema 18)
	
### Descriere:

Exista un anumit stoc din mai multe tipuri de bunuri (unele masurate la bucata
altele la greutate, altele la volum). Fiecare produs are un pret pe unitatea de masura si un
cost. Clientul soseste cu o lista de cumparaturi cu bunuri. Magazionerul ii comunica clientului
pretul total iar acesta decide daca cumpara sau nu. Daca cumpara se realizeaza, se produce
schimbul bunuri contra bani. La finalul zilei se realizeaza inchiderea zilei, afisand totaluri de
bunuri vandute si banii obtinuti. Scrieti un program care sa permita aceste operatiuni.

Precizari:
- Tipurile de Produsele pot fi cel putin: Varza (la buc), Faina (la kg) – cal. I, II sau III,
Bere la doza (buc) – cu Brand si tip (blonda/bruna), Vin varsat (rosu sec si alb sec)
– la volum, Vin de soi - la sticla (buc) – cu soi (Cabernet Savignon (rosu sec),
Merlot (rosu dulce), Savignon Blanc (alb dulce), Chardonnay (alb dulce) ), an
culegere si tara de origine (Franta, Argentina, Chile, Australia); Cartofi (la Kg) –
rosii sau albi si Jucarii (la buc) – unicat (cu nume text).
- Magazinul detine Articole de stoc.
- Clientul poate specifica vag produsele, omitand anumite trasaturi (eg. Vin, Vin
rosu; Faina) sau detaliat (vin rosu sec din 1996 din Franta). Magazionerul propune
cele mai profitabile variante avand in vedere precizarile clientului si disponibilul
de stoc.
- In lista de cumparaturi a clientului se pot repeta tipuri de produs.
## Proiect 3: Agentie imobiliara (Tema 10)
### Descriere: 

Se dorește implementarea unei aplicații care sa permita gestionarea clienților și a proprietăților imobiliare în cadrul unei agenții imobiliare nou infiintate. Pentru fiecare locuință se cunoaște numele clientului care o închiriază, suprafata utila și discount-ul (0-10%). La apartamente se cunoaste etajul, iar la case se stie cati metri patrati are curtea, cate etaje are casa și care este suprafata utila pe fiecare etaj în parte. 

Evident, calculul chiriei se face diferit. Dacă la apartamente se considera doar formula data de prețul de închiriere pe metru pătrat * suprafata utila, avand grija sa se aplice discount unde este cazul, la casa, se adaugă, indiferent de discount, prețul pe metru pătrat de curte * suprafața acesteia.

Structura de date: **set<pair<locuinta, tip>>** unde tip = apartament sau casa
 
Cerința suplimentară: 
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template Gestiune, continand structura de obiecte de tipul locuintelor implementate, alocat dinamic, unde indexul fiecărei locuințe este incrementat automat la adaugarea uneia noi, prin supraincarcarea operatorului +=. 
- Să se construiască o specializare pentru tipul Casa care sa stocheze numărul de case, fiecare cu chiria aferentă și afișează totalul obținut de agentia imobiliara de pe urma acestora. 
