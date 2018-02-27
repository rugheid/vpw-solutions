# Lees het aantal testgevallen n in
n = int(input())

# We gaan weer voor elk geval oplossen:
# De range is weer van 1 tot n+1 (dus tot en met n)
# omdat we van 1 moeten beginnen tellen en niet van 0
for geval in range(1, n+1):

    # Python leest altijd een hele lijn in, dus
    # we moeten die splitsten op spaties
    # In python splits een string door split()
    # We lezen dus de lijn in met input()
    # en splitsen die lijn op spaties met split()
    # De variabele `stappen` is nu een lijst
    # van strings, namelijk alle strings die
    # gescheiden waren door spaties.
    # Als voorbeeld kan je het volgende eens proberen:
    # "a bc def".split()
    # Dit gaat gelijk zijn aan ["a", "bc", "def"]
    stappen = input().split()

    # De eerste string van de lijn gaat het aantal
    # stappen zijn, maar dat hebben we niet nodig.
    # We kunnen die dus gewoon weggooien,
    # dat maakt het veel gemakkelijker.
    # In python gooi je een element uit een lijst
    # door del te gebruiken
    del stappen[0]

    # Nu moeten we de positie van de dronken man
    # berekenen. We houden zijn x en y positie
    # bij in twee variabelen: x en y
    # In het begin staat de man op 0, 0
    x = 0
    y = 0

    # We gaan nu elke stap bekijken en de
    # positie aanpassen.
    # In python kan je elk element in een lijst
    # bekijken door `for x in lijst` te gebruiken.
    # Je zou ook `for i in range(len(lijst))`
    # kunnen gebruiken en dan in de lus
    # `stap = lijst[i]` kunnen doen,
    # maar dat is langer en dit zegt heel duidelijk
    # wat we doen
    for stap in stappen:
        # We moeten nu de positie aanpassen
        # afhankelijk van wat voor stap we doen.
        # We doen dit gewoon met een hoop ifs.
        # Merk op dat we de onderste 3 ifs
        # kunnen vervangen door elif (wat
        # voor `else if` staat.
        if stap == "N":
            y += 1
        if stap == "O":
            x += 1
        if stap == "Z":
            y -= 1
        if stap == "W":
            x -= 1

    # We hebben nu de laatste positie en kunnen die printen
    print(geval, x, y)

    # De lus gaat nu naar het volgende testgeval
