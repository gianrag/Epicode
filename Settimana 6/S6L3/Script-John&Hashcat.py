import subprocess
import hashlib
import os

def crack_passwords(hash_value_file, tool='john'):
    # Verifica che lo strumento specificato sia valido
    if tool not in ['john', 'hashcat']:
        print("Strumento non valido. Scegliere 'john' o 'hashcat'.")
        return
    
    # Definisci il comando in base allo strumento scelto
    if tool == 'john':
        command = ['john', '--format=raw-md5', hash_value_file]
    elif tool == 'hashcat':
        command = ['hashcat', '-m', '0', '-a', '0', hash_value_file, '/usr/share/wordlists/rockyou.txt']
    
    try:
        # Esegui il comando per crackare le password
        result = subprocess.run(command, capture_output=True, check=True, text=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print("Errore nell'esecuzione del comando:", e)

def main():
    # Inserisci una lista di 5 password
    passwords = []
    for i in range(5):
        password = input(f"Inserisci la password {i+1}: ")
        passwords.append(password)
    
    # Calcola l'hash MD5 per ogni password
    hash_values = []
    for password in passwords:
        md5_hash = hashlib.md5(password.encode()).hexdigest()
        hash_values.append(md5_hash)

    # Stampa la lista degli hash MD5
    print("Lista degli hash MD5:")
    for hash_value in hash_values:
        print(hash_value)

    # Scrivi i valori degli hash in un file temporaneo
    hash_value_file = 'hash.txt'
    with open(hash_value_file, 'w') as f:
        for hash_value in hash_values:
            f.write(hash_value + '\n')

    # Scegli lo strumento (John the Ripper o hashcat) per crackare le password
    tool = input("Scegli lo strumento per crackare le password (john/hashcat): ").lower()
    
    # Crack delle password usando John the Ripper o hashcat
    crack_passwords(hash_value_file, tool=tool)

    # Rimuovi il file temporaneo
    os.remove(hash_value_file)

if __name__ == "__main__":
    main()
