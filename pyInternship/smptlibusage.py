# Simple Mail transfer protocol
import smtplib
content='Python says hello, thanks to smtplib';
#             SMTP Port number=====vvv
mail=smtplib.SMTP('smtp.gmail.com',587)
# Open the Port ^^
mail.ehlo
# Start Transfer Layer Security - Protect Sensitive Information
mail.starttls()
#              Sender's Email           and Password
# Allow Less secure Apps <- turn this option ON in GMail Settings so that it works
mail.login('arvindraj.thangraj16@siesgst.ac.in','password')
#                         Sender                           Receiver                Content
mail.sendmail('arvindraj.thangaraj16@siesgst.ac.in','arvindultimate7352@gmail.com',content)
mail.close()
