#!/bin/bash

# Definir macros para los colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # Sin color

print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}Test $2: PASSED${NC}"
    else
        echo -e "${RED}Test $2: FAILED${NC}"
    fi
}

# 1. Prueba de configuración de múltiples servidores con diferentes puertos
echo "1. Testing multiple servers with different ports"
curl -s http://localhost:8080 > /dev/null
print_result $? "1A. Server on port 8080"

curl -s http://localhost:8081 > /dev/null
print_result $? "1B. Server on port 8081"

# 2. Prueba de configuración de múltiples servidores con diferentes nombres de host
echo "2. Testing multiple servers with different hostnames"
curl -s --resolve example1.com:8082:127.0.0.1 http://example1.com:8082 > /dev/null
print_result $? "2A. Server with hostname example1.com"

curl -s --resolve example2.com:8083:127.0.0.1 http://example2.com:8083 > /dev/null
print_result $? "2B. Server with hostname example2.com"

# 3. Prueba de configuración de página de error por defecto
echo "3. Testing default error page setup"
response=$(curl -s -o /dev/null -w "%{http_code}" http://localhost:8084/nonexistent)
if [ "$response" -eq "404" ]; then
    echo -e "${GREEN}Test 3: PASSED${NC}"
else
    echo -e "${RED}Test 3: FAILED${NC}"
fi

# 4. Prueba de límite de tamaño del cuerpo del cliente
echo "4. Testing client body size limit"
response=$(curl -s --resolve localhost_body_limit:8085:127.0.0.1 -o /dev/null -w "%{http_code}" -X POST -H "Content-Type: text/plain" --data "$(head -c 15k </dev/urandom | base64)" http://localhost_body_limit:8085/)
if [ "$response" -eq "413" ]; then
    echo -e "${GREEN}Test 4: PASSED${NC}"
else
    echo -e "${RED}Test 4: FAILED${NC}"
fi

# 5. Prueba de configuración de rutas en un servidor a diferentes directorios
echo "5. Testing setup of routes to different directories"
curl -s --resolve localhost:8086:127.0.0.1 http://localhost:8086/site1 > /dev/null
print_result $? "5A. Route to /site1"

curl -s --resolve localhost:8086:127.0.0.1 http://localhost:8086/site2 > /dev/null
print_result $? "5B. Route to /site2"

# 6. Prueba de configuración de archivo por defecto al solicitar un directorio
echo "6. Testing setup of a default file for directories"
curl -s --resolve localhost:8087:127.0.0.1 http://localhost:8087/ > /dev/null
print_result $? "6. Default file for directories"

# 7. Prueba de configuración de métodos aceptados para una ruta específica
echo "7. Testing setup of allowed methods for a specific route"
curl -s --resolve localhost_methods:8088:127.0.0.1 -X GET http://localhost_methods:8088/restricted > /dev/null
print_result $? "7A. GET method on /restricted"

response=$(curl -s --resolve localhost_methods:8088:127.0.0.1 -o /dev/null -w "%{http_code}" -X POST http://localhost_methods:8088/restricted)
if [ "$response" -eq "403" ]; then
    echo -e "${GREEN}Test 7B: PASSED${NC}"
else
    echo -e "${RED}Test 7B: FAILED${NC}"
fi

# 8. Prueba de métodos aceptados para una ruta con y sin permiso
echo "8. Testing setup of allowed and disallowed methods for a route"
curl -s --resolve localhost_methods:8088:127.0.0.1 -X DELETE http://localhost_methods:8088/delete > /dev/null
print_result $? "8A. DELETE method allowed on /delete"

response=$(curl -s --resolve localhost_methods:8088:127.0.0.1 -o /dev/null -w "%{http_code}" -X POST http://localhost_methods:8088/delete)
if [ "$response" -eq "403" ]; then
    echo -e "${GREEN}Test 8B: PASSED${NC}"
else
    echo -e "${RED}Test 8B: FAILED${NC}"
fi

