# Image
FROM debian:buster

# Mainteners
LABEL maintainer="ajupiter@student.42.fr"

# Updating the image
RUN apt-get update \
    && apt-get -y upgrade

# Installing the dependencies
RUN apt install -y wget \
                   unzip \
                   nginx \
                   default-mysql-server \ 
                   php7.3 \
                   php7.3-fpm \
                   php7.3-mysql

# Generating the certificates (SSL)
RUN mkdir -p /etc/nginx/ssl/private \
    && mkdir -p /etc/nginx/ssl/certs \
    && openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/private/wordpress.key -out /etc/nginx/ssl/certs/wordpress.crt -subj "/C=FR"

# Installing WordPress
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz \
    && tar -zvxf latest-fr_FR.tar.gz -C /var/www/ \
    && rm -rf latest-fr_FR.tar.gz

# Installing phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.zip \
    && unzip phpMyAdmin-5.0.2-all-languages.zip -d /var/www/ \
    && mv /var/www/phpMyAdmin-5.0.2-all-languages/ /var/www/phpmyadmin/ \
    && rm -rf phpMyAdmin-5.0.2-all-languages.zip

# Configuring the services
ADD srcs/wp-config.php /var/www/wordpress/
ADD srcs/services /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/services /etc/nginx/sites-enabled/

# Adding wordpress mysql database configuration
ADD srcs/init_wordpress.sql .

# Exposing ports
EXPOSE 80 \
       443

# Starting services
CMD service nginx start \
    && service php7.3-fpm start \
    && service mysql start \
    && mysql < init_wordpress.sql \
    && rm init_wordpress.sql \
    && tail -f /dev/null
