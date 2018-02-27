# Lees het aantal testgevallen T in
T = int(input())

# Voor elk testgeval:
# We gaan de waarde `geval` nodig hebben voor het printen straks
# We moeten ook beginnen bij 1. Omdat we tot en met T moeten gaan,
# moeten we de range tot T+1 nemen.
# Je zou evengoed range(T) kunnen gebruiken en dan bij het
# printen geval+1 printen.
for geval in range(1, T+1):

    # Maak een lege lijst om de waardes in op te slaan
    waardes = []

    # Begin met het lezen van de waardes.
    # While True zou op zich oneindig lang doorgaan, maar we gaan
    # break gebruiken om te stoppen eens we stop tegenkomen
    while True:
        # Lees een waarde val in. val is een string!
        val = input()
        # We kunnen val vergelijken met "stop" omdat het een string is
        # Als het gelijk is aan stop, dan stoppen we de lus
        # Alle waarden zijn dan ingelezen
        if val == "stop":
            # break stopt de lus
            break
        # Hier geraken we alleen als val niet stop is
        # We voegen dan de waarde toe aan de lijst met waardes
        # Omdat we seffens met getallen (kommagetallen) willen
        # werken, nemen we float(val)
        # waardes.append(...) voegt een waarde toe achteraan de lijst
        # van waardes
        waardes.append(float(val))

    # Nu komt het stuk waar we zoeken naar een hittegolf
    # We leggen later uit waarvoor de volgende boolean waarde dient
    hitte_golf_gevonden = False

    # Ons algoritme gaat het volgende doen:
    # We proberen elke mogelijke dag uit als de begindag van de hittegolf
    # Voor elk van die begindagen kijken we hoe ver we kunnen doorgaan
    # met waardes die >= 25 zijn.
    # Als een waarde < 25, dan stopt de hittegolf daar sowieso.
    # Ondertussen houden we ook bij hoeveel dagen er >= 30 zijn,
    # want we hebben er minstens 3 nodig om een hittegolf te zijn.

    # Dus voor elke begindag:
    # We gebruiken len(waardes) - 5, omdat een hittegolf minstens 5 dagen
    # lang moet zijn, maar je kan ook len(waardes) gebruiken
    for begindag in range(len(waardes)-5):

        # We gaan nu elke dag bekijken vanaf de begindag en zolang
        # die >= 25 zijn.
        # We maken een nieuwe variabele dag die bijhoudt welke dag we
        # aan het bekijken zijn.
        # In het begin is die gelijk aan de begindag
        dag = begindag

        # We houden twee variabelen bij om te tellen hoeveel dagen >= 25
        # zijn (goed) en hoeveel >= 30
        aantal_goed = 0
        aantal_30 = 0

        # We blijven verder gaan zolang de dagen nog niet op zijn
        # (dag < len(waardes))
        # en zolang de waarde >= 25
        # (waardes[dag] >= 25)
        while dag < len(waardes) and waardes[dag] >= 25:
            # We hebben 1 extra goede dag
            aantal_goed += 1
            # En als de waarde >= 30, dan hebben we een extra dag >= 30
            if waardes[dag] >= 30:
                aantal_30 += 1
            # We hebben alles geteld, dus we gaan naar de volgende dag
            # Als nu de volgende dag < 25 bijvoorbeeld, dan gaan de
            # while lus stoppen.
            dag += 1

        # We hebben nu geteld hoe lang de periode van waardes >= 25 duurt
        # Dit is gewoon aantal_goed.
        # Merk op dat het kan dat aantal_goed 0 is, als de begindag zelf
        # niet >= 25.
        # We weten ook hoeveel dagen er >= 30 zijn.
        # Een hittegolf was gedefinieerd als een periode van minstens
        # 5 dagen >= 25 met minstens 3 dagen >= 30
        # Dus als dat zo is, dan hebben we de eerste hittegolf gevonden
        # en printen we die.
        if aantal_goed >= 5 and aantal_30 >= 3:
            # Print het gevalnummer, de begindag en de lengte
            # We printen begindag+1, omdat ze de eerste dag nummer 1
            # geven, waar we in python bij 0 beginnen
            print(geval, begindag+1, aantal_goed)
            # Dit leggen we seffens uit
            hitte_golf_gevonden = True
            # We hebben een hittegolf gevonden, dus we moeten niet meer
            # verder zoeken naar een goede begindag.
            # We gebruiken break om uit deze lus te springen.
            break
        # Als deze if niet waar was, dus als we geen hittegolf hebben
        # die begint op deze begindag, dan gaan we naar de volgende stap
        # in de lus. Dit betekent dat we de volgende dag gaan proberen
        # als begindag

    # Eens we hier zijn aangekomen, is de zoektocht naar een hittegolf
    # gedaan. Er kunnen twee dingen zijn gebeurd:
    # 1. We hebben een hittegolf gevonden en zijn gestopt met de lus
    #    door het gebruik van een break
    # 2. We hebben er geen gevonden en alle dagen geprobeerd
    # Bij geval 2 moeten we "geen hittegolf" printen, maar daarvoor
    # moeten we weten of er een hebben gevonden of niet.
    # Om dat bij te houden gebruiken we een boolean variabele
    # Dit is een variabele die waar of vals is (True of False in Python)
    # Helemaal in het begin van het algoritme zetten we die of False,
    # want we hebben op dat moment nog geen hittegolf gevonden.
    # Als we een hittegolf vinden, dan zetten we hem op True.
    # Als we er geen vinden, dan gaat hij dus nog gewoon op False staan.
    # Hier moeten we dus enkel "geen hittegolf" printen als we
    # er geen gevonden hebben:
    if not hitte_golf_gevonden:
        print(geval, "geen hittegolf")

    # We hebben nu dit testgeval afgerond.
    # Daarna gaat de volgende stap in de lus beginnen die
    # hetzelfde doet voor het volgende testgeval
