# Arkanoid remastered (Akční hra)
Autor: Matěj Gorgol

## Téma z Progtestu
Implementujte jednoduchou střílecí hru alespoň jednoho hráče proti počítači.

Hra musí splňovat následující funkcionality:

1. Objekty, které je možné zničit (nepřátelské jednotky, statické barikády)
2. Pohybovat s hráčem (chůze panáčka, let vesmírné lodi, páčka na odrážení míčků)
3. Po zničení objektu s určitou pravděpodobností zůstane bonus, implementujte několik různých bonusů (munice, rychlejší nabíjení,...)
4. Implementujte jednoduchý "fyzikální" model (setrvačnost lodi, gravitace, odrážení, nabíjení zbrani,...)
5. Implementujte načítání (generátoru) mapy ze souboru a ukládání nejlepších skóre do souboru.

Kde lze využít polymorfismus? (doporučené)

- Rozdělení objektů: (ne)pohyblivý, hráč vs. nepřítel
- Různé bonusy: munice, silnější zbraně, zdvojení zbraní, rychlejší přebíjení,...
- Uživatelské rozhraní: konzole, ncurses, SDL, OpenGL (různé varianty), ...

# Zadání hry

Jedná se o klasickou hru Arkanoid. Cílem hry je zničit všechny bloky a nenechat míček "spadnout" na zem.
Hra se ovládá šipkami (pohyb platformy doleva, doprava), mezerníkem (vypuštění míčku) a escapem (ukončení hry).

Jednotlivé herní objekty jsou implementovány jako dědicové třídy `GameObject`, ve které se nacházejí
 všechny základní a nutné informace. Jednotliví dědicové si potom přidávají další potřebné informace a metody, popřípadě
 přetěžují metody třídy `GameObject`.
 
 Herní smyčka se nachází ve třídě `Game`, která zároveň spravuje i herní okno a objekty.
 
 Rozmístění bloků se bude dát načítat ze souboru pomocí třídy `MapLoader` a bude uloženo ve třídě `Map`.
 
 ### Kde mám polymorfismus?
 
 Polymorfismus se nachází ve třídě `GameObject`, která obsahuje několik plně virtuálních metod. Metody `Init` a 
 `Update` jsou ty, ve kterých se nachází polymorfismus. Ve třídě `Ball` slouží metoda `Update` k udržení setrvačnosti
 míčku a případné změně směru (kolize se stěnou). Ve třídě `Bonus` slouží tato metoda k vytvoření "gravitace" (bonus padá k zemi).
 Dále třída `Block` má přetíženou metodu `Render`, kvůli využití sprite textury u této třídy (potřebujeme vědět kterou část textury chceme zobrazit).
 
> Polymorfismus pro bonusy zde nemám. Různé bonusy zatím řeším switchem. Pokud se to stane nepřehledné (velmi pravděpodobné),
> implemtuji jej.

>Implementovat jiné uživatelské rozhraní nehodlám (musím mít čas na Overwatch C: ), v úvaze je ale přidání menu
> s nastavením a tlačítkem "play" 
