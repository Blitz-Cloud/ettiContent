---
title: matLabIntro
date: 2025-10-24T20:45:44+03:00
subject: blog
description: 
tags: []
uniYearAndSemester: 21
---


```matlab
save datafile.mat
clear
load datafile.mat
```

```matlab
format long <VARIABLE>
```

```matlab
% timpuri de vectori, matrici

% vector cu un 2 coloane si un singur rand
% row vector
a=[7,8] 

% vector cu o singura coloana si 2 randuri
% column vector
a=[7;8]

% matrice cu 3 coloane si 2 randuri
c= [5 6 7; 8 9 10]

```

```matlab
% creeaza un vector cu elemente de la 1 la 10
x=1:10
% 0.5 reprezinta pasul de incrementare
z=1:0.5:5
% creaza un vector cu 5 numere de la 1 la 10  distribuite uniform
b = linspace(1,10,5)
% pt a transpune un vector se foloseste ' ca operator
b=b'
```

#### Functii pentru a crea numere aleatorii
```matlab
% creaza o matrice patratica de latura 5 cu elemete aleatorii
x=rand(5)

% de asemnea rand are urmatorul prototip rand(nr_randuri,nr_coloane), in cazul in care nr_coloane nu este specificat, acesta va fi egal cu nr_randuri
% astfel se poate genera o matrice de 3 randuri si 2 coloane
y=rand(3,2)

% pt a genera matrici doar cu 0 sau 1 se folosesc functiile zeros(nr_randuri,nr_coloane) sau ones(nr_randuri,nr_coloane)

% folosind functia size se poate determina dimensiunea unei matrici

% unclassified

x=randi(20,4,7)


```
#### Unele functii pot intoarce mai mult decat o singura variabila
1. max() poate fi folosit pt a obtine atat valoarea cat si index-ul 
2. size() poate fi folosit pt a obtine dimensiunile matricii(cate coloane, cate randuri)
3. pt a ignora o valoare se poate folosi ~

```matlab
[value,index] = max(<MATRIX>)
[~,column] = size(<MATRIX>) 
```

#### Grafice
```matlab
plot(x_axis,y_axis,"color_line_marker")
plot(sample,mass2,"r-*")
```
1. r = este rosu
2. k = este negru
3. s = este markerul de patrat

Pentru a afisa 2 seturi de date(beeMonitor) se paote folosi **hold on** si pentru a opri acest comportament se foloseste **hold off**