from django.shortcuts import render, get_object_or_404, redirect
from django.utils import timezone
from .models import Voiture

def voitures_a_vendre(request):
	cars_for_sale = Voiture.objects.filter(a_vendre=True).order_by('date_ajout')
	return render(request, 'vav/voitures-a-vendre.html', { 'voitures_a_vendre': cars_for_sale })

def voitures_vendues(request):
	cars_sold = Voiture.objects.filter(vendue=True).order_by('date_vente')
	return render(request, 'vav/voitures-vendues.html', { 'voitures_vendues': cars_sold })

def index(request):
	cars_for_sale = Voiture.objects.filter(a_vendre=True).order_by('date_ajout')
	cars_sold = Voiture.objects.filter(vendue=True).order_by('date_vente')
	return render(request, 'vav/index.html', { 'voitures_a_vendre': cars_for_sale, 'voitures_vendues': cars_sold })

def erreur_404(request):
	return redirect("index")
