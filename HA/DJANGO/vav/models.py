from django.db import models
from django.utils import timezone

class Voiture(models.Model):
	titre = models.TextField()
	titre_vignette = models.TextField()
	prix = models.TextField(blank=True)
	annee = models.TextField(blank=True)
	km = models.TextField(blank=True)
	type_voiture = models.TextField(blank=True)
	transmission = models.TextField(blank=True)
	couleur_ext = models.TextField(blank=True)
	couleur_int = models.TextField(blank=True)
	moteur = models.TextField(blank=True)
	puissance = models.TextField(blank=True)
	type_essence = models.TextField(blank=True)
	plus = models.TextField(blank=True)
	options_1 = models.TextField(blank=True)
	options_2 = models.TextField(blank=True)
	date_ajout = models.DateTimeField(default=timezone.now)
	a_vendre = models.BooleanField(default=True)
	vendue = models.BooleanField(default=False)
	date_vente = models.DateTimeField(blank=True, null=True)
	index = models.BooleanField(default=False)
	photo1 = models.FileField(blank=True, upload_to='images')
	photo2 = models.FileField(blank=True, upload_to='images')
	photo3 = models.FileField(blank=True, upload_to='images')
	photo4 = models.FileField(blank=True, upload_to='images')
	photo5 = models.FileField(blank=True, upload_to='images')
	photo6 = models.FileField(blank=True, upload_to='images')
	photo7 = models.FileField(blank=True, upload_to='images')
	photo8 = models.FileField(blank=True, upload_to='images')
	photo9 = models.FileField(blank=True, upload_to='images')
	photo10 = models.FileField(blank=True, upload_to='images')
	photo11 = models.FileField(blank=True, upload_to='images')
	photo12 = models.FileField(blank=True, upload_to='images')

	@property
	def photo_list(self):
		photo_fields = [self.photo1, self.photo2, self.photo3, self.photo4, self.photo5, self.photo6, self.photo7, self.photo8, self.photo9, self.photo10, self.photo11, self.photo12]
		photos = []
		for photo in photo_fields:
			if photo:
				try:
					photos.append(photo)
				except ValueError:
					pass
		return photos

	def __str__(self):
		return self.titre
