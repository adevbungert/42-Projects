from django.conf.urls import url
from . import views

urlpatterns = [
	url(r'^$', views.index, name='index'),
	url(r'^index.html', views.index, name='index'),
	url(r'^voitures-a-vendre.html$', views.voitures_a_vendre, name='voitures_a_vendre'),
	url(r'^voitures-vendues.html$', views.voitures_vendues, name='voitures_vendues'),
#	rajouter cette redirection lorsqu'on mettra le site en production
#	en local ca bug
#	url(r'^.*$', views.erreur_404),
]
