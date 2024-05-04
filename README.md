# ICP Projekt VUT FIT 2024

## Téma: 2D simulátor mobilitních robotů

Jedná se o jednoduchou simulaci pohybu a kolizí robotů v 2D prostoru.
Roboti se pohybují v prostoru s překážkami.
Součástí aplikace je možnost vytváření simulace (roboti, překážky) a možnost ukládání a načítání simulace ze souboru.
Roboti se mohou pohybovat autonomně nebo manuálně.

Program je napsán v jazyce C++ s využitím knihovny Qt pro grafické rozhraní.

## Autoři:

- **Mifka Radim (xmifka00)**

## Poznámky:

- Nesprávné zobrazení hodnoty aktualizované orientace pohledu robota po kolizi v políčku parametru. (Pouze vizuální chyba políčka - robot se chová správně)

## Použití:

### Simulace

- spuštěna kliknutím na tlačítko "Start" v sekci "Simulation".
- zastavena kliknutím na tlačítko "Stop" v sekci "Simulation".
- načtena z json souboru kliknutím na tlačítko "Load" v sekci "Simulation".
- uložena do json souboru kliknutím na tlačítko "Save" v sekci "Simulation".

### Překážky

- vytvářeny kliknutím na tlačítko "Obstacle" v sekci "Spawn".
- mazány kliknutím na tlačítko "Remove" v sekci "Spawn".
- vytvářeny jako se základními parametry, které jsou určeny v souboru `Settings.hpp`.
- Jejich poloha lze měnit kliknutím na ně a následným přetažením.
- Jejich vlastnosti lze měnit kliknutím na ně a následně změnou hodnot v sekci "Obstacle parameters".
- Změny se projeví hned po změně hodnoty.

#### Parametry překážek:

- Pozice X, Y
- Velikost
- Natočení

### Roboti

- vytvářeni kliknutím na tlačítko "Autonomous Robot" nebo "Manual Robot" v sekci "Spawn".
- mazáni kliknutím na tlačítko "Remove" v sekci "Spawn".
- vytvářeni se základními parametry, které jsou určeny v souboru `Settings.hpp`.
- Jejich poloha lze měnit kliknutím na ně a následným přetažením.
- Jejich vlastnosti lze měnit kliknutím na ně a následně změnou hodnot v sekci "Robot parameters".
- Změny se projeví hned po změně hodnoty.

#### Manuální ovládání:

- Robota s manuálním ovládáním je možné ovládat pomoc klávesových zkratek (W, A, S, D).
- Robot lze ovládat i pomocí tlačítek v sekci "Manual Controls".

#### Parametry robotů:

- Pozice X, Y
- Velikost
- Délka zorného pole
- Orientace pohledu
- Úhel otáčení
- Rychlost
- Směr otáčení

## Vzhled:

Vzhled aplikace je možné menit v souboru `Settings.hpp`.

- Veškeré barvy
- Velikost okna
- Rychlost simulace
- Parametry robotů
- Parametry překážek

## Klávesové zkratky:

### Obecné:

- `DELETE` - Mazání vybraného objektu

### Manuální robot:

- `W` - Pohyb vpřed
- `S` - Zastavení
- `A` - Otočení doleva
- `D` - Otočení doprava
