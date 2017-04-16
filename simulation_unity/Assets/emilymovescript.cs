using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class emilymovescript : MonoBehaviour {
	private Rigidbody rb;
	public float speed;
	void Start()
	{
		rb = GetComponent<Rigidbody> ();
	}
		
	
	// Update is called once per frame
	void FixedUpdate () {
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");
		//rotate EMILY
		transform.Rotate (new Vector3(0.0f,0.0f,-moveHorizontal*100) * Time.deltaTime);
		//add thrust to EMILY
		//transform.position = (new Vector3(0,0,moveVertical*speed)*Time.deltaTime);
		Vector3 movement = new Vector3(0,moveVertical,0);
		rb.AddRelativeForce (movement*speed);
		rb.drag = 1;
	}
}
